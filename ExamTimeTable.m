number_of_sub = input('Number of subjects = ');
constraint = zeros(number_of_sub, number_of_sub);
color = -ones(1,number_of_sub);
for i=1:number_of_sub
    for j=1:number_of_sub
        str = input('Enter condition = ','s'); 
        if str(1) == 'y'
            constraint(i,j) = 0;
            constraint(j,i) = 0;
        else
            constraint(i,j) = 1;
            constraint(j,i) = 1;
        end
    end
end
color(1,1) = 1;
number_of_colors = 1;
for i=2:number_of_sub
    flag = 0;
    available = ones(1,number_of_colors);
    for j=1:i-1
        if constraint(i,j) == 1
            available(1,color(1,j)) = 0 ;
        end
    end
    for j=1:number_of_colors
        if available(1,j) == 1
            color(1,i) = j;
            flag = 1;
            break;
        end
    end
    
    if flag == 0 
        number_of_colors = number_of_colors + 1;
        color(1,i) = number_of_colors;
    end
end
number_of_colors