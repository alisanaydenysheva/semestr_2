# Задания и требования - https://docs.google.com/presentation/d/17YdUQJrXn2dPckjSeDarp3v6mYDyaHhsLKEFe0GpqEk/edit#slide=id.gd19284b371_0_0


# Защита OpenCV
1. Какие есть варианты записи времени в языке С++ и юникс системах
1) Clock, hrono
2) (дата) - (Время в секундах с 1970).
3. Потоки записи и чтения файла
4. ofstream file;ifstream f(File)
 (Предлоги out in)
 Ifstrem - ввод 
 Ofstream - вывод
5. Что тако объявление и вызов функции
6. При объявление указывает тип аргументов(void), при вызове не указывается. У самой функции есть фигурные скобочки в которых написан код. 
7. Как происходит вывод картинки на картинку
 Mat small = imread("da.jpg");
addWeighted(small, 0.6, im, 0.4, 0, im);
10. Как происходит обрабтка нажатия мыши
 if (event == EVENT_LBUTTONDOWN
