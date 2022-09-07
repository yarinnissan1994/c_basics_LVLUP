#include <stdio.h>

int main()
{
    /* switch(5)
    {
        default:
        printf("invalid number");
        break;

        case 1:
        printf("1");
        break;

        case 2:
        printf("2");

        case 3:
        printf("3");

        case 4:
        printf("4");
        break;
        }
        */

        //1
        /*
        for(int i = 1;i<=10;i++)
        {
            if (i!=7)
            {
                printf("%d\n",i);
            }
        }
        */

        //2
        /*
        for(int i = 1;i<100;i++)
        {
            int a3 = i%3;
            int a7 = i%7;
            if(a3==0 || a7==0)
            {
                printf("%d\n",i);
            }
        }
        */

        //3
        /*
        void func1()
        {
        int input;
        int num = 1;
        int hold;
        printf("please enter a number:");
        scanf("%d",&input);
        for(int i = 1;i<=input;i++)
        {
            hold = num;
            num=i*num;
            printf("%dX%d=%d\n",i,hold,num);
        }
        }

        func1();
        */

        //4
        /*
        int func2(int a,int b)
        {
            int sum = a;
            for(int i = 1;i<b;i++)
            {
                sum=sum*a;
            }
            printf("%d",sum);
            return sum;
        }

        func2(2,3);
        */

        //hm1
        /*
        int lastnum(int num)
        {
            while(num >= 10)
            {
                if(num > 1000)
                {
                    num = num - 1000;
                }
                else if(num > 100)
                {
                    num = num - 100;
                }
                else if (num > 10)
                {
                    num = num - 10;
                }
            }
            printf("%d", num);
            return 0;
        }

        lastnum(9432);
        */

        //hm2
        /*
        int secondlast(int num)
        {
            while(num >= 100)
            {
                if(num > 1000)
                {
                    num = num - 1000;
                }
                else if(num > 100)
                {
                    num = num - 100;
                }
            }
            if(num >= 10 && num <= 19)
            {
                num = 1;
            }
            else if(num >= 20 && num <= 29)
            {
                num = 2;
            }
            else if(num >= 30 && num <= 39)
            {
                num = 3;
            }
            else if(num >= 40 && num <= 49)
            {
                num = 4;
            }
            else if(num >= 50 && num <= 59)
            {
                num = 5;
            }
            else if(num >= 60 && num <= 69)
            {
                num = 6;
            }
            else if(num >= 70 && num <= 79)
            {
                num = 7;
            }
            else if(num >= 80 && num <= 89)
            {
                num = 8;
            }
            else if(num >= 90 && num <= 99)
            {
                num = 9;
            }
            else
            {
                num = 0;
            }
            printf("%d", num);
            return 0;
        }

        secondlast(43129);
        */

        //hm3
        /*
        int prime(int num)
        {
            int count = 0;
            int ind;
            for(int i = 1;i<=num;i++)
            {
                ind = num%i;
                if(ind==0)
                {
                    count++;
                }
            }
            if(count<=2)
            {
                printf("%d is a prime number", num);
            }
            else
            {
                printf("%d is not a prime number", num);
            }
            return 0;
        }

        prime(12);
        */

        //hm4
        /*
        void prime100()
        {
            int count = 0;
            int ind;
            for(int j = 1;j<100000;j++)
            {
                for(int i = 1;i<=j;i++)
                    {
                        ind = j%i;
                        if(ind==0)
                        {
                            count++;
                        }
                    }
                if(count<=2)
                    {
                        printf("%d is a prime number\n", j);
                    }
                    count = 0;
            }
        }

        prime100();
        */

        //hm5
        /*
        int mirror(int num)
        {
          int hold = num;
          int r = 0;

          while (hold != 0)
          {
            r = r * 10;
            r = r + hold%10;
            hold = hold/10;
          }

          if(num == r)
          {
              printf("the number %d is a mirrored number", num);
          }
          else
          {
              printf("the number %d is not a mirrored number", num);
          }

          return 0;
        }

        mirror(12344321);
        */


    return 0;
}

