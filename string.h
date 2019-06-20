#include<string.h>
void* memchr(const void*, int, size_t);
int memcmp(const void*,const void*, size_t);
void* memcpy(void*, const void*, size_t);
void* memmove(void*, const void*, size_t);
void* memset(void*, int, size_t);

//-------------------------------------------------------------------------
char* strncat(char*, const char*, size_t);

//find first occurrence of c in s[n]
void* memchr(const void *s, int c, size_t n)
{
    const unsigned char* su = (const unsigned char*)s;
    const unsigned char uc = c;
    while(n>0)
    {
        if(*su == c)
            return (void*)su;
        ++su;
        --n;
    }
    return NULL;
}

int memcmp(const void *s1, const void *s2,size_t n)
{
    const unsigned char* u1 = (const unsigned char*)s1;
    const unsigned char* u2 = (const unsigned char*)s2;
    while(n>0)
    {
        if(*s1 != *s2)
            return *s1 - *s2;
        ++s1;
        ++s2;
        --n;
    }
    return 0;
}

void* memcpy(void *dst, const void *src, size_t n)
{
    char* d = (char*)dst;
    const char* s = (const char*)src;
    while(n>0)
    {
        *d++ = *s++;   
        --n;
    }
    return dst;
}

void* memmove(void *s1, const void* s2, size_t n)
{
    char *d = (char*)s1;
    const char* s = (const char*)s2;
    if(s<d)
    {
        while(n>0)
        {
            *(d+n-1) = *(s+n-1);
            --n;
        }
    }
    else if(s > d)
    {
        while(n>0)
        {
            *d++ =*s++;
            --n;
        }
    }
    return d;
}

void* memset(void* dst, int c, size_t n)
{
    unsigned char *d = (unsigned char*)dst;
    const unsigned char v = c;
    while(n>0)
    {
        *d++ = v;
        --n;
    }
    return dst;    
}

char* strncat(char* d, const char* s, size_t n)
{
    char *tmp = d;
    
    while(*tmp)
    {
        ++tmp;
    }
    while(n>0 && *s != '\0')
    {
        *tmp++ = *s++;
        --n;
    }
    *tmp = '\0';
    return d;
}

int strncmp(const char* s1, const char* s2, size_t n)
{
    while(n>0)
    {
        if(*s1 != *s2)
        {
            return *s1 - *s2;
        }
        else if(*s1 == '\0')
            return 0;
        ++s1;
        ++s2;
        --n;
    }
    return 0;
}


char* strncpy(char *dst, const char* src, size_t n)
{
    char *d = dst;
    while(n>0 && *src != '\0')
    {
        *d++ = *src++;
        --n;
    }
    for(;0<n;--n)
        *d++ = '\0';
    return dst;
}

char* strcat(char *s1, const char* s2)
{
    char *s =s1;
    for(;*s!='\0';+=s);
    for(;(*s=*s2)!='\0';++s,++s2);
    /*while(*s != '\0')
    {
        ++s;
    }
    while(*s2 != '\0')
    {
        *s++ = *s2++;
    }
    *s = '\0';*/
    return s1;
}

int strcmp(const char* s1, const char* s2)
{
    for(;*s1 == *s2;++s1,++s2)
    {
        if(*s1 == '\0')
            return 0;
    }
    return *s1 - *s2;

    /*while(true)
    {
        if(*s1 != *s2)
        {
            return *s1 - *s2;
        }
        else if(*s1 == '\0')
            return 0;
        ++s1;
        ++s2;        
    }*/

}

char* strcpy(char* dst, const char* src)
{
    char *d = dst;
    for(;(*d++=*src++)!='\0';);
    return dst;
}

size_t strlen(const char* s)
{
    int n = 0;
    for(int n=0;(*s++)!='\0';++n);
 
    while(*s != '\0')
    {
        ++n;
        ++s;
    }
    return n;
}
