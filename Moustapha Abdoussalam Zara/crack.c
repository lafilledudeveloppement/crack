# define _XOPEN_SOURCE
# include <unistd.h>
# include <stdio.h>
# include<string.h>
# include <cs50.h>

int main(int argc, string argv[])
{
    if(argc != 2)
    {
        printf("Usage: crack <hash>\n");
        return 1;
    }

    const int alphabet_count=53;

    string alphabet="\0abcdefghijklnmopqrstuvwxyzABCDEFGHIJKLNMOPQRSTUVWXYZ";
    string hash = argv[1];

    char salt[3];
    memcpy(salt,hash,2);
    salt[2]= '\0';

    char key_student[6]="\0\0\0\0\0\0";

    for(int i=0; i<alphabet_count; i++)
    {
        for(int j=0; j<alphabet_count; j++)
        {
            for(int k=0; k<alphabet_count; k++)
            {
                for(int l=0; l<alphabet_count; l++)
                {
                    for(int n=0;n<alphabet_count; n++)
                    {
                        key_student[0]= alphabet[n];
                        key_student[1]=alphabet[l];
                        key_student[2]=alphabet[k];
                        key_student[3]=alphabet[j];
                        key_student[4]=alphabet[i];

                        if(strcmp( crypt(key_student, salt),hash) ==0)
                        {

                            printf("%s\n", key_student);
                            return 0;
                        }

                    }
                }
            }
        }
    }


printf("Password couldn't be cracked!");
return 2;
}

