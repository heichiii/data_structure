#include<stdio.h>
#include<fstream>
#include<iostream>
struct Node
{
    struct Node *left;
    struct Node *right;
    int val;
    char ch;
};

Node *nodes[128];
int nptr=0,ptr=0;
int count[128]={0};
char buffer[1000];
char debuffer[1000];
char code[128][200]={0};
char tch[200];
int tptr=0;

void sort()
{
    for(int i=0;i<nptr;i++)
    {
        for(int j=i+1;j<nptr;j++)
        {
            if(nodes[j]->val>nodes[i]->val)
            {
                Node *t=nodes[j];
                nodes[j]=nodes[i];
                nodes[i]=t;
            }
        }
    }
}
void dfs(Node *node)
{
    if(node==NULL)return;
    if(node->ch!=-1)
    {
        for(int i=0;i<tptr;i++)
        {
            code[node->ch][i]=tch[i];
        }
    }
    tch[tptr++]='0';
    dfs(node->left);
    tptr--;

    tch[tptr++]='1';
    dfs(node->right);
    tptr--;
}


char str_travel(char ch[],Node *node,int l)
{
    Node *t_node=node;
    for(int tr_int=0;tr_int<l;tr_int++)
    if(ch[tr_int]=='0')
    {
        t_node=t_node->left;
    }
    else if(ch[tr_int]=='1')
    {
        t_node=t_node->right;
    }
    return t_node->ch;
}

int main()
{
    FILE *read_file=fopen("src.txt","r");
    char t;
    while((t=fgetc(read_file))!=EOF)
    {
        buffer[ptr++]=t;
        count[t]++;
    }

    for (int i=0;i<128;i++,nptr++)
    {
        nodes[nptr]=(Node *)malloc(sizeof(Node));
        nodes[nptr]->left=NULL;
        nodes[nptr]->right=NULL;
        nodes[nptr]->ch=i;
        nodes[nptr]->val=count[i];
    }

    while(nptr>1)
    {
        sort();
        Node *tempnode=(Node *)malloc(sizeof(Node));
        tempnode->left=nodes[--nptr];
        tempnode->right=nodes[--nptr];
        tempnode->val=tempnode->left->val+tempnode->right->val;
        tempnode->ch=-1;
        nodes[nptr++]=tempnode;
    }
    
    dfs(nodes[0]);
    
    FILE *huf_file=fopen("HufTree.txt","w");
    for (int i=0;i<128;i++)
    {
        fprintf(huf_file,"%s\n",code[i]);
    }

    FILE *code_file=fopen("encode.txt","w");
    for(int i=0;i<ptr;i++)
    {
        fprintf(code_file,"%s-",code[buffer[i]]);
    }

    fclose(huf_file);
    fclose(code_file);
    fclose(read_file);

    int deptr=0;
    FILE *decode_file=fopen("encode.txt","r");
    FILE *wdecode_file=fopen("decode.txt","w");
    char tt;
    std::cout<<"Have creat \nHuffmantree in Huftree.txt\nPressed src.txt's Huffmancode in encode.txt\ndepress encode.txt in decode.txt\n";
    std::cout<<"decode.txt's content:";
    while((tt=fgetc(decode_file))!=EOF)
    {
        if(tt!='-')
        {
            debuffer[deptr++]=tt;
        }
        else
        {
            char ttt=str_travel(debuffer,nodes[0],deptr);
            deptr=0;
            fprintf(wdecode_file,"%c",ttt);
            std::cout<<ttt;
        }
    }
    fclose(decode_file);
    fclose(wdecode_file);
    
}