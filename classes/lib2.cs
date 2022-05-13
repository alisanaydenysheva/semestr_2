using System;
using System.Collections.Generic;
using System.Linq;

namespace ConsoleApptestnew1
{
    class Program
    {
        /* static double MinAVG(string[] marks)
         {
             int[] a = new int[marks.Length];
             Class1.test_function();
             Console.WriteLine();
             int b = 0;
             for (int i = 0; i < marks.Length; i++)
             {
                 //Console.WriteLine(marks[i]);
                 a[i] = Convert.ToInt32(marks[i]);
                 b += a[i];
                 int c = (b / marks.Length);
                 Console.WriteLine(b);
                 Console.WriteLine(c);
             }
             return 0;
         }*/
        static string GetStudNumber(int year, int group, string fio)
        {


            string[] init = fio.Split(' ');
            string i = init[0];
            string i2 = init[1];
            string i3 = init[2];
            char a = i[0];
            char b = i2[0];
            char c = i3[0];
            string denis = year + "." + group + "." + a + b + c;
            return denis;
        }

        static public void Main(string[] args)
        {
            /*Console.WriteLine("Напишите ваш год рождения");
            int year = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Напишите номер вашей группы");
            int group = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Введите вше ФИО");
            String fio = Console.ReadLine();*/

            // Console.WriteLine(GetStudNumber(year, group, fio));
            //string[] marks = { "5", "4", "3" };
            //Class1.MinAVG(marks);
            Students students1 = new Students();
            students1.grupa = 195;
            students1.god = 2000;
            students1.FIO = "DEN KAR VIK";
            DateTime now = DateTime.Now;
            List<string> students = new List<string>();
            students.Add(students1.FIO);

            for (int i = 0; i < 10; i++)
            {

                Students students2 = new Students();
                string c = "Student" + Convert.ToString(i);
                students2.FIO = c;
                students2.grupa = 195;
                students2.god = 2000;
                students.Add(students2.FIO);
                Console.WriteLine(students[i]);


            }
            // students.ForEach(p => Console.WriteLine($"{p.FIO}"));
            List<Mark> a = GetMarks(now, students);
            Console.WriteLine(GetCountDisease(a));
            Console.WriteLine(GetCountTruancy(a));



        }

        public static List<Mark> GetMarks(DateTime now, List<string> students)
        {
            List<Mark> res = new List<Mark>();
  Random rnd = new Random();

            for (int i = 0; i < 30; i++)
            {
                string[] bcv = { "Б", "П", "У", "2", "3", "4", "5" };
              
                int value = rnd.Next(bcv.Length);
                Mark mark = new Mark();
                mark.date = now.AddDays(i);
                mark.progul = bcv[value];
                res.Add(mark);



            }

            for (int j = 0; j < 10; j++)
            {
                Console.WriteLine(students[j]);
                Console.WriteLine(GetCountDisease(res));
                Console.WriteLine(GetCountTruancy(res));
                res.ForEach(p => Console.WriteLine($"{p.date}, {p.progul} "));
            }
            return res;
        }


        public static int GetCountDisease(List<Mark> marks)
        {
            
                var Bol = from p in marks
                                     where p.progul == "Б"
                                     select p;
            int count = 0;
            foreach (Mark mark in Bol)
            {
                count++; 
            }

            return count;
        }

        public static int GetCountTruancy(List<Mark> marks)
        {

            var Prog = from p in marks
                      where p.progul == "П"
                      select p;
            int countt = 0;
            foreach (Mark mark in Prog)
            {
                countt++;
            }

            return countt;
        }
    }
    public class Students
    {
        public int grupa;
        public int god;
        public string FIO;

    }
    public class Mark
    {
        public DateTime date;
        public string progul;
    }
}
