% Часть 2
% А) 1) Выбрать из таблицы 2 закон распределения дискретной случайной величины
% в соответствии с нашим вашим вариантом
% X  0.4   0.5   1.3   2.7   3.9
% P  0.1   0.4   0.1   0.1   0.3

% 2) Смоделировать 10000 значений этой случайной величины

N = 10000;
selection = zeros(1, N);
for i = 1:N
   x = rand();
   if (0 <= x) && (x < 0.1)
       selection(i) = 0.4;
   elseif (0.1 <= x) && (x < 0.5)
       selection(i) = 0.5;
   elseif (0.5 <= x) && (x < 0.6)
       selection(i) = 1.3;
   elseif (0.6 <= x) && (x < 0.7)
       selection(i) = 2.7;
   else
       selection(i) = 3.9;
   end
end

% 3) В математическом пакете Matlab провести расчет выборочного среднего и
% исправленной выборочной дисперсии по получившейся выборке данных

selMean = mean(selection);
selVar = var(selection) * N / (N - 1);

% 4) Провести в математическом пакете расчет математического ожидания и
% дисперсии по теоретическим формулам. Сравнить получившиеся значения со
% значениями выборочного среднего и исправленной выборочной дисперсии из
% предыдущего пункта и сделать выводы

counts = zeros(1, 5);
for i = selection
   if i == 0.4
       counts(1) = counts(1) + 1;
   elseif i == 0.5
       counts(2) = counts(2) + 1;
   elseif i == 1.3
       counts(3) = counts(3) + 1;
   elseif i == 2.7
       counts(4) = counts(4) + 1;
   else
       counts(5) = counts(5) + 1;
   end
end
selTMean = (counts(1) * 0.4 + counts(2) * 0.5 + counts(3) * 1.3 + counts(4) * 2.7 + counts(5) * 3.9) / N;
disp(num2str(selMean));
disp(num2str(selTMean));
selTVar = (counts(1) * 0.4^2 + counts(2) * 0.5^2 + counts(3) * 1.3^2 + counts(4) * 2.7^2 + counts(5) * 3.9^2) / N;
selTVar = selTVar - selTMean^2;
disp(num2str(selVar));
disp(num2str(selTVar));

% 5) Построить на одном графике полигон частот по полученной выборке из
% 10000 чисел, а также многоугольник распределения по исходному
% распределению из таблицы 2 в соответствии с вашим вариантом. Сравнить и
% сделать выводы.

figure;
plot([0.4, 0.5, 1.3, 2.7, 3.9], counts / N, [0.4, 0.5, 1.3, 2.7, 3.9], [0.1, 0.4, 0.1, 0.1, 0.3]);
legend("Полигон построенный на выборке", "Полигон построенный по таблице");
title("Полигоны частот")
xlabel("x");
ylabel("n");

clear N;
clear selection;
clear selMean;
clear selTMean;
clear Var;
clear selTVar;
clear counts;

% Б) Моделирование значений непрерывной случайности величины методом
% обратных функций
% 1) Выбрать из таблицы 3 плотность вероятности f(x) непрерывной случайной
% величины в соответствии с вашим вариантом

% 1.5 * x^(0.5)  (0, 1)

% 2) Смоделировать 10000 значений этой случайной величины

N = 10000;
selection = zeros(1, N);
for i = 1:N
    x = rand();
    selection(i) = x^(2/3);
end

% 3) В математическом пакете Matlab провести расчет выборочного среднего и
% исправленной выборочной дисперсии по получившейся выборке данных

selMean = mean(selection);
selVar = var(selection) * N / (N - 1);

% 4) Провести в математическом пакете расчет математического ожидания и дисперсии по теоретическим формулам.
% Сравнить получившиеся значения со значениями выборочного среднего и
% исправленной выборочной дисперсии из предыдущего пункта и сделать выводы.

funcMean = @(x) 1.5.*x.^(1.5);
selTMean = integral(funcMean, 0, 1);
funcDisp = @(x) 1.5.*x.^(0.5).*(x - selTMean).^2;
selTVar = integral(funcDisp, 0, 1);
disp("-----------------------");
disp(num2str(selMean));
disp(num2str(selTMean));
disp(num2str(selVar));
disp(num2str(selTVar));


% 5) Построить гистограмму относительных частот по сгенерированной в п.2.
% выборке данных и нанести на этот же график плотность вероятности из
% таблицы 3 в соответствии с вашим вариантом. Сравнить и сделать выводы.

selection = sort(selection);
r = ceil(1 + 3.222 * log10(N));
h = (max(selection) - min(selection)) / r;
z = zeros(1, r + 1);  % создаем массив с r + 1 элементами
xmin = min(selection);
for i = 1:r + 1  % Заполняем его границами
   z(i) = xmin + h * (i - 1); 
end

vCount = zeros(1, r);  % Делаем вектор с количеством элементов в каждой группе выборки
k = 1;  % Номер интервала
for i = selection  % Проходим по каждому элементу
    while (k + 1 ~= r + 1 && i > z(k + 1))  % Корректирование номера интервала
       k = k + 1;
    end
    vCount(k) = vCount(k) + 1;  
end

centers = zeros(1, r);  % Вычисляем координаты центров
for i = 1:r
    centers(i) = xmin + h / 2 + h * (i - 1);
end

nvCount = zeros(1, r);

for i = 1:r  % Нормируем длины столбцов гистограммы
    nvCount(i) = vCount(i) / (h * N);
end

figure;  % Создаем новое окно
bar(centers, nvCount, 1);  % Отрисовываем столбцы гистограммы (1 - ширина столбца в процентах)
hold on;
x = 0:0.001:1;
y = 3/2.*x.^(0.5);
p = plot(x, y);
p.LineWidth = 2;
title("Сравнение гистограммы относ. частот с плотностью вероятности");
xlabel("x");
ylabel("n");

% 6) Построить эмпирическую функцию распределения по получившейся в п. 1
% выборке данных и на этом же графике построить теоретическую функцию
% распределения, которую предварительно необходимо найти по заданной из
% таблицы 3 плотности вероятности, соответствующей вашему варианту.

noGrpFunc = zeros(1, N);  % Массив для негруппированной выборки
for i = 1:N
    noGrpFunc(i) = sum(selection <= selection(i)) / N;  % Значение эмпирической функции для каждого элемента выборки
end

figure;
x = 0:0.001:1;
y = x.^(1.5);
plot(selection, noGrpFunc, x, y);
title("Сравнение теоретической и эмпирической функции распределения");
legend("Эмпирическая функция", "Теоретическая функция");
xlabel("x");
ylabel("p");
