#pragma once
#include "stdafx.h"
#define MAX_STRING 255
#define MAX_CHAR 1
#define IN_MAX_LEN_TEXT 1024*1024
#define IN_MAX_STRING_CODE 1024
#define IN_CODE_ENDL '\n'
#define IN_CODE_SPACE ' '
#define IN_CODE_NULL '\0'

/*
S - ( ) * + - = , / { } ; ! & % [ ] < >
PR - ������ � TAB
NS - ����� ������
F - �����������
T - �����������
I - ������������
K - '
*/

#define IN_CODE_TABLE {\
		/*0*/	/*1*/  /*2*/  /*3*/  /*4*/  /*5*/  /*6*/  /*7*/  /*8*/  /*9*/  /*A*/  /*B*/  /*C*/  /*D*/  /*E*/  /*F*/\
/*0*/	IN::F,  IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::P, IN::N, IN::F, IN::F, IN::I, IN::F, IN::F,\
/*1*/	IN::F,  IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F,\
/*2*/	IN::P,  IN::S, IN::F, IN::F, IN::F, IN::S, IN::S, IN::K, IN::S, IN::S, IN::S, IN::S, IN::S, IN::S, IN::F, IN::S,\
/*3*/	IN::T,  IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::S, IN::S, IN::S, IN::S, IN::T,\
/*4*/	IN::F,  IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T,\
/*5*/	IN::T,  IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::S, IN::F, IN::S, IN::F, IN::F,\
/*6*/	IN::F,  IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T,\
/*7*/	IN::T,  IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::S, IN::F, IN::S, IN::F, IN::F,\
		 /*0*/	/*1*/  /*2*/  /*3*/  /*4*/  /*5*/  /*6*/  /*7*/  /*8*/  /*9*/  /*A*/  /*B*/  /*C*/  /*D*/  /*E*/  /*F*/\
/*8*/	IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F,\
/*9*/	IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F,\
/*A*/	IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F,\
/*B*/	IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F,\
/*C*/	IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T,\
/*D*/	IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T,\
/*E*/	IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T,\
/*F*/	IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T,\
}  

namespace In
{
	struct Words
	{
		char word[1024];
		int line; // ������ � ������� ��������� �����
		static int amount;  // ���������� ����
	};

	struct IN
	{
		enum { T = 1, F, I, N, S, P, K };
		int code[256] = IN_CODE_TABLE;
		int size = NULL;
		int lines = NULL; //������� ��������� � 1?
		int ignor = NULL;
		bool flag = 0;
		unsigned char* text;
		Words* words;
	};

	IN getin(std::ofstream* stream, wchar_t Infile[]);
	Words* split(Words* words, unsigned char* text, int* code); //��������� �������� ��� �� �����
	void newWord(Words* words, char*& Buffer, int& posbuf, int line);
}