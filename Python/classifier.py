import numpy as np
import theano.tensor as T
from theano_ops.Ops import dense
from theano_ops.activations import softmax, sigmoid, relu
from theano_ops.base_model import TheanoModel
from theano_ops.utils import to_categorical
from theano_ops.optimizers import Adam


class SpineClassifier(TheanoModel):
    def _def_tensors(self):
        self.x = T.matrix('x', 'float32')
        self.y = T.matrix('y', 'int8')

    def _def_arch(self, init_params=None):
        params = self.get_params('d1', init_params)
        self.dense1, params = dense(self.x, self.get_shape(self.x)[1], 45, layer_name='d1', init_params=params)
        self.params += params
        self.to_regularize.append(params[0])
        
        params = self.get_params('d2', init_params)
        self.dense2, params = dense(sigmoid(self.dense1), self.get_shape(self.dense1)[1], 2, layer_name='d2', init_params=params)
        self.params += params
        self.to_regularize.append(params[0])

        self.logits = softmax(self.dense2)
        self.outputs = self.logits

    def _def_cost_acc(self):
        l2_norm_squared = sum([(p**2).sum() for p in self.to_regularize])
        self.cost = T.sum((T.sub(self.outputs, self.y))**2).mean() + self.lmbd * l2_norm_squared
        diff = abs(T.argmax(self.outputs, axis=1) - T.argmax(self.y, axis=1))
        self.acc = T.sub(1, 1.*T.nonzero(diff)[0].shape[0] / self.y.shape[0])


if __name__ == "__main__":
    # x_train = np.load('train_x.npy').astype('float32')
    # y_train = to_categorical(np.load('train_y.npy')).astype('int8')
    
    # x_test = np.load('test_x.npy').astype('float32')
    # y_test = to_categorical(np.load('test_y.npy')).astype('int8')

    M = SpineClassifier(batch_size=16, input_shape=(1, 252), optimizer=Adam(lr=1e-4), metrics=['loss', 'acc'], init_params=SpineClassifier.restore_params('ckpts/model_snapshot.npy'))
    #M.train(x_train=x_train, y_train=y_train, x_validation=x_test, y_validation=y_test, nb_epochs=1000)

    import cv2
    from extractFeatures import extractFeatures
    from theano_ops.utils import normalize
    img = cv2.imread('train_data/notLamina/IMG_64.jpg', 0)
    import time
    t = time.time()
    inpt = np.array(extractFeatures(normalize(img))).reshape((1, -1))
    print M.predict(inpt.astype('float32'))
    print time.time() - t