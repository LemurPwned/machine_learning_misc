%in this version cities can be revisited, takes longer to converge
clc; clear;
N = 5;
cities = randi([1 20], 10, 10);
cities_test =  [9999, 5, 1, 2, 3;
                5, 9999, 4, 6, 3;
                1, 4, 9999, 2, 5;
                2, 6, 2, 9999, 7;
                3, 3, 5, 7, 9999];
for i=1:N
    for j=i:N
        if i == j
            cities(i,j) = 99999;
        else
            
            t = randi([1 N*2],1);
            cities(i,j) = t;
            cities(j,i) = t;
        end
    end
end
%change here to see randomly genrated graph
cities_test = cities_test


gen_num = 600;
count=0;
best_list = [];
%h = animatedline;
figure
hold on
xlim([-2 (N+2)])
ylim([N-2 (N*2+2)])
colors = ['oy','og','or','ob','ok'];

D(1,:) = randi([0 N],1,N);
D(2,:) = randi([N 2*N],1,N);
for i=1:N
    plot(D(1,i), D(2,i), 'o')
    legendInfo{i} = ['City ' num2str(i)];
end

legend(legendInfo);
%legend('1','2','3','4','5', '6', '7', '8', '9', '10')
for i =1:2*N+2
    lh(i) = line([0 0], [6 6]);
end
%% 1. we need to generate sets of random paths, a population
pop_size = 10;
path_len = 2*N + 2;
p = zeros(pop_size, path_len);
rank = zeros(pop_size, 1);
for i=1:pop_size
    p(i,:)=[randperm(N+1)-1, randperm(N+1)-1];
end
p;

while (count < gen_num)
    %% 2. rank population
    if count > 100
        if ((mean(best_list(end-100 : end)) == best_list(end)))
            disp('No significant change in last 100 generations')
            break;
        end
    end
    count=count+1;
    rank = zeros(1,pop_size);
    for k=1:pop_size
        for c=2:path_len
            if p(k,c-1)==0 && p(k,c)~=0
                rank(k) = 999999;
            elseif p(k,c-1)==0 && p(k,c)==0
                rank(k) = rank(k) + 0;
            elseif p(k,c-1)~=0 && p(k,c)==0
                rank(k) = rank(k) + 0;
            else
                rank(k) = rank(k) + cities_test(p(k, c-1), p(k,c));
            end;
        end
    end
    %two minimum values
    [a, ai] = min(rank);
    [b, bi] = max(rank);
    [c, ci] = max(rank(rank<max(rank)));
    [d, di] = min(rank(rank>min(rank)));
    %[b, bi] = min(rank(rank>min(rank)));
    best_list(count) = a;
    rank;
    if mod(count, 10) == 0
        disp(a);
        disp(p(ai, :));
    end
    t = 2;
    new_pop(1, :) = p(ai, :);
    if ~isempty(di)
        new_pop(2, :) = p(di, :);
        t = 3;
    end
    
    for c=2:path_len
        if p(ai, c) == 0 || p(ai, c-1) == 0
            break;
        else
            set(lh(c),'XData',[D(1,p(ai,c-1)) D(1,p(ai,c))], 'YData', [D(2,p(ai,c-1)) D(2,p(ai,c))]);
            drawnow()
        end
    end
        pause(0.025)
    %kill last two weaklings
    p(bi,:) = [randperm(N+1)-1, randperm(N+1)-1];
    if ~isempty(ci)
        p(ci,:) = [randperm(N+1)-1, randperm(N+1)-1];
    end
   
        
    for z=t:pop_size
        indiv_pair = randi([1 pop_size],1,2);
        crossover_index = randi([1 path_len], 1);
        %new_pop(z, :) = [p(indiv_pair(1,1), 1:crossover_index) p(indiv_pair(1,2), crossover_index+1:end)]; 
        temp = [p(indiv_pair(1,1), 1:crossover_index) p(indiv_pair(1,2), crossover_index+1:end)];
        while (min(ismember(1:N,temp)) == 0)
            indiv_pair = randi([1 pop_size],1,2); 
            crossover_index = randi([1 path_len], 1);
            temp = [p(indiv_pair(1,1), 1:crossover_index) p(indiv_pair(1,2), crossover_index+1:end)];    
        end 
        new_pop(z, :) = temp;
    end
 
    new_pop;

    %% 3. Mutate the population
    mutation_rate = 0.05*3;
    mut_object = randi([3 pop_size],1, round(mutation_rate*pop_size));
    for j=1:size(mut_object,2)
        elements_to_swap = randi([1 path_len], 1,2);
        obA = new_pop(mut_object(1,j), elements_to_swap(1,1));
        new_pop(mut_object(1,j),elements_to_swap(1,1)) = new_pop(mut_object(1,j), elements_to_swap(1,2));
        new_pop(mut_object(1,j),elements_to_swap(1,2)) = obA;
    end
    %this mutations zeros something just in second half
    mut_object = randi([3 pop_size],1, round(mutation_rate*pop_size));
    for j=1:size(mut_object,2)
        elements_to_zero = randi([N+1 path_len], 1);
        obA = new_pop(mut_object(1,j), elements_to_swap(1,1));
        new_pop(mut_object(1,j),elements_to_zero(1,1)) = 0;
    end
    p = new_pop;
end            
new_pop;
disp(a);
disp(p(ai, :));
figure
plot(best_list(1,:), 'r')