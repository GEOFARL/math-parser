# Математичний інтерпритатор

## Корисні посилання та джерела, що були використані

[Video about what the parser is and its types](https://www.youtube.com/watch?v=OIKL6wFjFOo)

[Wiki article about lexical analysis](https://en.wikipedia.org/wiki/Lexical_analysis)

[Wiki about parser in general and parsing process](https://en.wikipedia.org/wiki/Parsing)

[Wiki on recursive descent parsers](https://en.wikipedia.org/wiki/Recursive_descent_parser)

[cpp reference on regex](https://en.cppreference.com/w/cpp/regex)

[cpp reference on regex_search](https://en.cppreference.com/w/cpp/regex/regex_search)

[cpp reference on enums](https://en.cppreference.com/w/cpp/language/enum)

[cpp reference on pair](https://en.cppreference.com/w/cpp/utility/pair)

[video explaining CFG and PEG in detail](https://www.youtube.com/watch?v=lJcK9-0daBY)

[cpp reference on function wrappers](https://en.cppreference.com/w/cpp/utility/functional/function)

[a series of articles on parsing topic](https://inspirnathan.com/posts/149-math-expression-parser-in-javascript)

## Завдання

Написати програму-інтерпретатор математичних виразів, що підтримує змінні та (в більш складному варіанті) оператори розгалуження. Можете взяти за основу вашу або чиюсь попередню лабораторну роботу із Shunting Yard.

В цій роботі замість того, щоб одразу обчислювати значення кожної операції, необхідно спочатку побудувати абстрактне синтаксичне дерево виразу. Далі обчислення виразу зводиться до обходу дерева в глибину і обчислення значення вузлів дерева або прийняття рішення про зміну порядку обходу дерева. Як приклад, можна навести умовний оператор: обчислюється лише одна з гілок вершини цього оператора, а інша пропускається.

Значення змінних під час обходу дерева найкраще зберігати в хеш-таблиці. Ніякі типи даних, крім чисел із плаваючою комою, впроваджувати не обов\'язково.

AST використовують щоразу при компіляції програм написаних практично всіма мовами програмування. Наприклад, наступному фрагментові коду (приклад з вікіпедії)

```
while b ≠ 0
  if a > b
    a := a − b
  else
    b := b − a
return a
```

може відповідати таке дерево:

<img src="https://upload.wikimedia.org/wikipedia/commons/thumb/c/c7/Abstract_syntax_tree_for_Euclidean_algorithm.svg/1024px-Abstract_syntax_tree_for_Euclidean_algorithm.svg.png" height="400">

### Вхідні та вихідні дані

На вхід програмі подається текстовий файл з кодом, наприклад:

```
abc = 1;
q = 3;
2+abc*q;
```

Програма має вивести результат обчислення останнього виразу на екран:
`result = 5.0`
