//ВСТАВИТЬ КРАСОТУ

#include <fstream>
#include <iostream>
using namespace std;

/***************************************************************/
/*          П Р О Т О Т И П Ы    Ф У Н К Ц И Й                 */
/***************************************************************/
//
// 
// 

int letters(const int real_len_str, int real_len_sl, char slovo_array[], char stroka_array[]);

//void letters(const char* fname_IN //имя исходного файла
//    , char* xStr1         //ПОЛНОЕ имя
//    , char* xStr2);       //ГОРОД

//
//void amount(const char* xfname_OUT //имя результирующего файла
 //   , char* xStr             //строка
 //   , int xNum);             //число

/**************************************************************/
/*            О С Н О В Н А Я   П Р О Г Р А М М А             */
/**************************************************************/

int main()
{
    //инициализация
    const int max_len = 1024;   //максимальная длина строки и слова
    int real_len_sl = 0;        //реальная длина слова
    int real_len_str = 0;       //реальная длина строки
    char slovo_array[max_len];  //слово
    char stroka_array[max_len] = ""; //строка слов
    int i = 0;


    ifstream slovo_file("slovo.txt"); //объект для управления потоком ввода из файла
    ifstream stroka_file("stroka_slov.txt");



    slovo_array[0] = '\0';              //очистить строку
    stroka_array[0] = '\0';             //очистить строку

    slovo_file.getline(slovo_array, max_len);
    cout << slovo_array << endl;


    stroka_file.getline(stroka_array, max_len);
    cout << stroka_array << endl;

    while (slovo_array[i] != '\0')
    {
        i++;
        real_len_sl++;
    }

    cout << real_len_sl << endl;

    i = 0;
    while (stroka_array[i] != '\0')
    {
        i++;
        real_len_str++;
    }//while

    cout << real_len_str << endl;
    
    letters(real_len_str, real_len_sl, slovo_array, stroka_array);
    return 0;
}



int letters(const int real_len_str, int real_len_sl, char slovo_array[], char stroka_array[])
{
  int CountWordSymb = 0;   // счетчик слов с заданным символом
  int NWord = 0;           // счетчик слов
  char PatternSymb = ' ';
  bool FindSymb = false;
  //цикл по длине строки
  int bw = 0;    //индекс начала слова
  int ew = 0;    //индекс конца слова
  int i = 0;    //индекс текущей позиции в строке
  int j;

  for (int k = 0;k < real_len_sl; k++)
  {
    PatternSymb = slovo_array[k];
    cout << PatternSymb << endl;
    while (i < real_len_str)    //пока не кончилась строка
    {
      //пропускаем пробелы, если таковые есть и строка не кончилась
      while ((stroka_array[i] == ' ') && (i < real_len_str))  //"   ABCBAA  BABBS     CCCC"
      {
        i++;    // к следующему пробелу
      } // end while

      //двигаемся по слову, ищем конец слова 
      bw = i;   //знаем начало слова
      ew = bw;  //начало и конец слова вначале совпадают

      //пока не пробел (слово не кончилось) и строка не кончилась
      while ((stroka_array[i] != ' ') && (i < real_len_str)) //"   ABCBAA  BABBS     CCCC"
      {
        i++;    // к следующей букве
        ew++;    //передвигаем указатель конца слова
      } // end while  
      ew--;  //вернулись на последнюю букву слова
      //индекс i указывает на первый символ за словом или концом строки !!!!!

      cout << "\tbw = " << bw << "\tew = " << ew << endl;

      //ищем в слове заданную букву
      FindSymb = false;      //заданный символ не нашли
      for (j = bw; j <= ew; j++)  //по длине слова
      {
        if (PatternSymb == stroka_array[j]) // нашли заданный символ
        {
          FindSymb = true;
          //break;  //незачем смотреть дальше, уже нашли
        }//IF
      } //end for j

      //проверим с чем вышли из цикла
      if (FindSymb)    //заданный символ в слове есть
      {
        CountWordSymb++; // увеличим счетчик слов с заданным символом
        cout << "Cлово, содержащее символ <" << PatternSymb
          << ">\t<";
        for (j = bw; j <= ew; j++)  //печать слова с заданным символом
        {
          cout << stroka_array[j];
        } //end for j
        cout << ">\n\n";

      } // end if

  }

  

  } // end while по длине строки

  return 1;
}


//первая процедура
  //печать слов с буквами
  //печать количества букв в этих словах


//Вторая процедура
  //печать количество этих слов