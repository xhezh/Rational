A. Rational

  Ограничение времени	1 секунда
  Ограничение памяти	64.0 Мб
  Ввод	стандартный ввод или input.txt
  Вывод	стандартный вывод или output.txt
  В качестве решения ожидается zip архив с решением (даже если решение состоит из одного файла). Присылайте файлы только с ВАШИМ кодом, то есть файлы с тестами и CMakeLists.txt присылать не нужно.

Условие
  В C++ существует множество встроенных типов данных для работы с целочисленной арифметикой и арифметикой над числами с плавающей точкой. Однако при вычислениях над последними возможны ошибки
  округления, которые могут накапливаться при сложных (состоящих из множества операций) вычислениях. Если при работе с иррациональными числами округлений избежать не получится, то в программах,
  требующих манипуляций только с рациональными числами, все вычисления можно свести к точной целочисленной арифметике. Именно это вам и предстоит проделать в данном задании.

Детали реализации
  Необходимо реализовать класс для работы с рациональными числами Rational.

  Рациональное число представляется двумя взаимно простыми целыми числами - числителем и положительным знаменателем. Этот инвариант необходимо поддерживать при выполнении любых операций над объектами класса Rational. Публичный интерфейс класса должен включать:

  Конструктор по умолчанию, который инициализирует число нулем;
  Неявный конструктор преобразования от целых чисел (должен работать следующий код Rational x = 5;). Не забудьте добавить комментарий // NOLINT (см. замечания);
  Конструктор от двух целых чисел (числитель и знаменатель). При этом не гарантируется, что числа взаимно простые и ненулевые (об этом далее);
  Методы GetNumerator() и GetDenominator(), возвращающие числитель и знаменатель соответственно;
  Методы SetNumerator(int) и SetDenominator(int), устанавливающие числитель и знаменатель в требуемые значения;
  Бинарные арифметические операции (+, -, /, *) и их присваивающие версии (+=, -=, /=, *=);
  Унарные операции (+, -), а также префиксные и постфиксные инкременты и декременты (++, --);
  Операции сравнения;
  Операции ввода из потока и вывода в поток (>>, <<);
  При выводе числа в поток необходимо выводить его в виде несократимой дроби в формате <числитель>/<знаменатель> либо <числитель>, если знаменатель равен 1. Ввод осуществляется в том же формате (но дробь на входе необязательно несократима).

Пример:

  Rational x = 5;        // дробь 5/1
  std::cout << x;        // вывод: 5
  x.SetDenominator(15);  // дробь 1/3 (5/15 сократилась)
  std::cout << x;        // вывод: 1/3
  std::cin >> x;         // ввод: 14/-6, дробь: -7/3 (общий множитель 2; знаменатель > 0)
  
Деление на 0
  При делении на 0 (в операции деления или при установке знаменателя в 0) программа должна сообщать об ошибке. Для этих целей в C++ есть механизм исключений. Исключение - объект некоторого класса, который унаследован от стандартного класса ошибки библиотеки C++. Если не все ясно сейчас, то это ok, если не все понятно перед зачетом или экзаменом - у вас проблемы.

  Класс ошибки RationalDivisionByZero написан за вас, вам лишь требуется в момент, когда происходит деление на ноль, сообщить об ошибке с помощью строки: throw RationalDivisionByZero{};

Замечания.

  Решение должно состоять из файлов rational.h (объявления) и rational.cpp (определения). Если для решения вам требуются другие компилируемые файлы с реализацией, их стоит добавить в переменную RATIONAL_SRC в файле CMakeLists.txt.
  Хорошей идеей будет вынести логику сокращения дроби в отдельный метод.
  std::gcd можно использовать.
  Гарантируется, что числитель и знаменатель в любой момент помещаются в int32_t.
  Кодстайл запрещает неявные конструкторы преобразования (и правильно делает), но в этой задаче неявное преобразование из целых чисел в рациональное вполне осмысленно. Чтобы чекер проигнорировал проверку строки с объявлением такого конструктора, добавьте комментарий // NOLINT к этой строке.
