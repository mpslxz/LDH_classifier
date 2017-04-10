for i = 1:575
    I = imread(sprintf('IMG_%d.jpg',i));
    I = im2double(I);
    flag = mod(i,4);
    switch flag
        case 0
            I = imnoise(I,'gaussian');
        case 1
            I = imnoise(I,'speckle');
        case 2
            I = imnoise(I,'salt & pepper');
        case 3
            I = imnoise(I,'poisson');
    end
    imwrite(I, sprintf('IMG_%d.jpg',i+575),'jpg');
    
end