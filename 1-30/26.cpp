#include <iostream>

struct IntArray {
  int *data = nullptr;
  int size;
};

void create(IntArray* arr, int size);
/** Создаёт динамический массив размера size и сохраняет его в поле data переменной arr. Поле size структуры arr становится равным параметру size */
int get(IntArray* arr, int index);
/** Возвращает элемент массива с индексом index, при этом проверяет выход за границы массива. Если index лежит за пределами массива, вывести сообщение об ошибке и прервать работу программы */
void set(IntArray* arr, int index, int value);
/** Изменяет значение элемента массива с индексом index на значение параметра value, при этом проверяет выход за границы массива. Если index лежит за пределами массива, вывести сообщение об ошибке и прервать работу программы */
void print(IntArray* arr);
/** Выводит на экран содержимое массива в формате: [1, 2, 3] */
void resize(IntArray* arr, int newSize);
/** Изменяет размер массива с сохранением элементов. Если новый размер меньше, хвостовые элементы обрезаются, если больше, то дополнительные элементы инициализируются нулём */
void free(IntArray* arr);
/** Освобождает память занятую массивом. Поле data становится равным nullptr, поле size становится равным нулю. Предусмотреть случай попытки удаления уже удалённого массива */
void append(IntArray* arr, int value);
/** Добавляет в конец (на место где 0), если последний индекс не 0 то увиличевает массив в 1.5 раза */
void IndexError(IntArray* arr, int index,const char f[10]);
/** Вызывается в случае выхода за пределы массива, выводит отчёт и завершает работу программы */


int main()
{
  IntArray intdata;
  create(&intdata, 30);
  for (int i = 0; i < intdata.size; i++)
  {
    set(&intdata, i, i+1);
  }	  
  print(&intdata);
  resize(&intdata, 50);
  print(&intdata);
  resize(&intdata, 10);
  print(&intdata);
  free(&intdata);
  return 0;
}


void print(IntArray* arr)
{
  if (arr->data == nullptr){std::cout << "data is not create\n";}
  else
  {
    std::cout << "[";
    int s = arr->size-1;
    for (int i = 0; i<s; i++){std::cout << arr->data[i] << ", ";}
    if (arr->size != 0){std::cout << arr->data[s];}
    std::cout << "]\n";
  }
}

void resize(IntArray* arr, int newSize)
{
  if (arr->data == nullptr) create(arr,newSize);
  else
  {
  int* olddata = arr->data;
  arr->data = new int[newSize];
  for (int i = 0;i<newSize;i++)
  {
    if (i<arr->size) arr->data[i] = olddata[i];
    else arr->data[i] = 0;
  }
  delete olddata;
  arr->size = newSize;
  }
}


void free(IntArray* arr)
{
  delete arr->data;
  arr->data = nullptr;
  arr->size = 0;
}

void create(IntArray* arr, int size)
{
  if (arr->data == nullptr) free(arr);
  arr->data = new int[size];
  arr->size = size;
  for (int i = 0;i<size;i++){arr->data[i] = 0;}
}

void IndexError(IntArray* arr, int index, const char f[10])
{
  std::cout << "IndexErorr: index = " <<  index << ", size = " << arr->size << ", function = " << f << "\ndata:\n";
  print(arr);
  srand(time(NULL));
  if (not rand()%21) std::cout << "\n03:14:08 19.01.2033\n";
  exit(1);
}

int get(IntArray* arr, int index)
{
  if (arr->size < index or index + arr->size < 0) IndexError(arr, index, "get");
  if (index < 0) index += arr->size;
  return arr->data[index];
}

void set(IntArray* arr, int index, int value)
{
  if (arr->size < index or index + arr->size < 0) IndexError(arr, index, "set");
  if (index < 0) index += arr->size;
  arr->data[index] = value;
}

void append(IntArray* arr, int value)
{
  if (arr->data == nullptr) create(arr, 1);
  int i = arr->size-1;
  for (;0 <= i;i--)
  {
    if (get(arr, i) != 0) 
      if (i == arr->size-1)
        { resize(arr,arr->size*15/10); append(arr, value); break;} 
      else {set(arr, i+1, value); break;};
  }
  if (i == -1) set(arr, 0, value);
}
