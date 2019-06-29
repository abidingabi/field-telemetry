/* Generated by Nim Compiler v0.11.2 */
/*   (c) 2015 Andreas Rumpf */
/* The generated code is subject to the original license. */
/* Compiled for: Windows, amd64, gcc */
/* Command for C compiler:
   g++.exe -c  -w -w -fpermissive  -IC:\Nim\lib -o c:\users\dansm\desktop\folders\robotics\field-telemetry\nimcache\stdlib_parseutils.o c:\users\dansm\desktop\folders\robotics\field-telemetry\nimcache\stdlib_parseutils.cpp */
#define NIM_INTBITS 64
#include "nimbase.h"
struct NimStringDesc;
struct TGenericSeq;
struct Overflowerror3443;
struct Arithmeticerror3439;
struct Exception;
struct TNimObject;
struct TNimType;
struct TNimNode;
struct Tcell46547;
struct Tcellseq46563;
struct Tgcheap48416;
struct Tcellset46559;
struct Tpagedesc46555;
struct Tmemregion28410;
struct Tsmallchunk27640;
struct Tllchunk28404;
struct Tbigchunk27642;
struct Tintset27617;
struct Ttrunk27613;
struct Tavlnode28408;
struct Tgcstat48414;
struct Tbasechunk27638;
struct Tfreecell27630;
struct  TGenericSeq  {
NI len;
NI reserved;
};
struct  NimStringDesc  : public TGenericSeq {
NIM_CHAR data[SEQ_DECL_SIZE];
};
typedef N_NIMCALL_PTR(void, TY3289) (void* p, NI op);
typedef N_NIMCALL_PTR(void*, TY3294) (void* p);
struct  TNimType  {
NI size;
NU8 kind;
NU8 flags;
TNimType* base;
TNimNode* node;
void* finalizer;
TY3289 marker;
TY3294 deepcopy;
};
struct  TNimObject  {
TNimType* m_type;
};
struct  Exception  : public TNimObject {
Exception* parent;
NCSTRING name;
NimStringDesc* message;
NimStringDesc* trace;
};
struct  Arithmeticerror3439  : public Exception {
};
struct  Overflowerror3443  : public Arithmeticerror3439 {
};
struct  TNimNode  {
NU8 kind;
NI offset;
TNimType* typ;
NCSTRING name;
NI len;
TNimNode** sons;
};
struct  Tcell46547  {
NI refcount;
TNimType* typ;
};
struct  Tcellseq46563  {
NI len;
NI cap;
Tcell46547** d;
};
struct  Tcellset46559  {
NI counter;
NI max;
Tpagedesc46555* head;
Tpagedesc46555** data;
};
typedef Tsmallchunk27640* TY28422[512];
typedef Ttrunk27613* Ttrunkbuckets27615[256];
struct  Tintset27617  {
Ttrunkbuckets27615 data;
};
struct  Tmemregion28410  {
NI minlargeobj;
NI maxlargeobj;
TY28422 freesmallchunks;
Tllchunk28404* llmem;
NI currmem;
NI maxmem;
NI freemem;
NI lastsize;
Tbigchunk27642* freechunkslist;
Tintset27617 chunkstarts;
Tavlnode28408* root;
Tavlnode28408* deleted;
Tavlnode28408* last;
Tavlnode28408* freeavlnodes;
};
struct  Tgcstat48414  {
NI stackscans;
NI cyclecollections;
NI maxthreshold;
NI maxstacksize;
NI maxstackcells;
NI cycletablesize;
NI64 maxpause;
};
struct  Tgcheap48416  {
void* stackbottom;
NI cyclethreshold;
Tcellseq46563 zct;
Tcellseq46563 decstack;
Tcellset46559 cycleroots;
Tcellseq46563 tempstack;
NI recgclock;
Tmemregion28410 region;
Tgcstat48414 stat;
};
typedef NI TY27620[8];
struct  Tpagedesc46555  {
Tpagedesc46555* next;
NI key;
TY27620 bits;
};
struct  Tbasechunk27638  {
NI prevsize;
NI size;
NIM_BOOL used;
};
struct  Tsmallchunk27640  : public Tbasechunk27638 {
Tsmallchunk27640* next;
Tsmallchunk27640* prev;
Tfreecell27630* freelist;
NI free;
NI acc;
NF data;
};
struct  Tllchunk28404  {
NI size;
NI acc;
Tllchunk28404* next;
};
struct  Tbigchunk27642  : public Tbasechunk27638 {
Tbigchunk27642* next;
Tbigchunk27642* prev;
NI align;
NF data;
};
struct  Ttrunk27613  {
Ttrunk27613* next;
NI key;
TY27620 bits;
};
typedef Tavlnode28408* TY28414[2];
struct  Tavlnode28408  {
TY28414 link;
NI key;
NI upperbound;
NI level;
};
struct  Tfreecell27630  {
Tfreecell27630* next;
NI zerofield;
};
N_NIMCALL(NI, npuParseBiggestInt)(NimStringDesc* s, NI64& number, NI start);
N_NIMCALL(NI, rawparseint_94914)(NimStringDesc* s, NI64& b, NI start);
static N_INLINE(NI, addInt)(NI a, NI b);
N_NOINLINE(void, raiseOverflow)(void);
N_NIMCALL(NI64, mulInt64)(NI64 a, NI64 b);
static N_INLINE(NI, subInt)(NI a, NI b);
static N_INLINE(NI64, subInt64)(NI64 a, NI64 b);
N_NIMCALL(void*, newObj)(TNimType* typ, NI size);
N_NIMCALL(NimStringDesc*, copyStringRC1)(NimStringDesc* src);
static N_INLINE(void, nimGCunrefNoCycle)(void* p);
static N_INLINE(Tcell46547*, usrtocell_50047)(void* usr);
static N_INLINE(void, nimFrame)(TFrame* s);
N_NOINLINE(void, stackoverflow_19801)(void);
static N_INLINE(void, popFrame)(void);
static N_INLINE(void, rtladdzct_51604)(Tcell46547* c);
N_NOINLINE(void, addzct_50017)(Tcellseq46563& s, Tcell46547* c);
N_NIMCALL(void, raiseException)(Exception* e, NCSTRING ename);
STRING_LITERAL(TMP219, "overflow", 8);
extern TNimType NTI23201; /* ref OverflowError */
extern TNimType NTI3443; /* OverflowError */
extern TFrame* frameptr_17042;
extern Tgcheap48416 gch_48444;

static N_INLINE(NI, addInt)(NI a, NI b) {
	NI result;
{	result = 0;
	result = (NI)((NU64)(a) + (NU64)(b));
	{
		NIM_BOOL LOC3;
		LOC3 = 0;
		LOC3 = (((NI) 0) <= (NI)(result ^ a));
		if (LOC3) goto LA4;
		LOC3 = (((NI) 0) <= (NI)(result ^ b));
		LA4: ;
		if (!LOC3) goto LA5;
{		goto BeforeRet;
}	}
	LA5: ;
	raiseOverflow();
	}BeforeRet: ;
	return result;
}

static N_INLINE(NI, subInt)(NI a, NI b) {
	NI result;
{	result = 0;
	result = (NI)((NU64)(a) - (NU64)(b));
	{
		NIM_BOOL LOC3;
		LOC3 = 0;
		LOC3 = (((NI) 0) <= (NI)(result ^ a));
		if (LOC3) goto LA4;
		LOC3 = (((NI) 0) <= (NI)(result ^ (NI)((NU64) ~(b))));
		LA4: ;
		if (!LOC3) goto LA5;
{		goto BeforeRet;
}	}
	LA5: ;
	raiseOverflow();
	}BeforeRet: ;
	return result;
}

static N_INLINE(NI64, subInt64)(NI64 a, NI64 b) {
	NI64 result;
{	result = 0;
	result = (NI64)((NU64)(a) - (NU64)(b));
	{
		NIM_BOOL LOC3;
		LOC3 = 0;
		LOC3 = (IL64(0) <= (NI64)(result ^ a));
		if (LOC3) goto LA4;
		LOC3 = (IL64(0) <= (NI64)(result ^ (NI64)((NU64) ~(b))));
		LA4: ;
		if (!LOC3) goto LA5;
{		goto BeforeRet;
}	}
	LA5: ;
	raiseOverflow();
	}BeforeRet: ;
	return result;
}

N_NIMCALL(NI, rawparseint_94914)(NimStringDesc* s, NI64& b, NI start) {
	NI result;
	result = 0;
	NI64 sign = IL64(-1);
	NI i = start;
	{
		NI TMP210;
		if (!((NU8)(s->data[i]) == (NU8)(43))) goto LA3;
{		TMP210 = addInt(i, ((NI) 1));
		i = (NI)(TMP210);
}	}
	goto LA1;
	LA3: ;
	{
		NI TMP211;
		if (!((NU8)(s->data[i]) == (NU8)(45))) goto LA6;
{		TMP211 = addInt(i, ((NI) 1));
		i = (NI)(TMP211);
		sign = IL64(1);
}	}
	goto LA1;
	LA6: ;
	LA1: ;
	{
		NI64 TMP217;
		NI TMP218;
		if (!(((NU8)(s->data[i])) >= ((NU8)(48)) && ((NU8)(s->data[i])) <= ((NU8)(57)))) goto LA10;
{		b = IL64(0);
		{
			while (1) {
				NI64 TMP212;
				NI TMP213;
				NI64 TMP214;
				NI TMP215;
				if (!(((NU8)(s->data[i])) >= ((NU8)(48)) && ((NU8)(s->data[i])) <= ((NU8)(57)))) goto LA13;
				TMP212 = mulInt64(b, IL64(10));
				TMP213 = subInt(((NI) (((NU8)(s->data[i])))), ((NI) 48));
				TMP214 = subInt64((NI64)(TMP212), ((NI64) ((NI)(TMP213))));
				b = (NI64)(TMP214);
				TMP215 = addInt(i, ((NI) 1));
				i = (NI)(TMP215);
				{
					while (1) {
						NI TMP216;
						if (!((NU8)(s->data[i]) == (NU8)(95))) goto LA15;
						TMP216 = addInt(i, ((NI) 1));
						i = (NI)(TMP216);
					} LA15: ;
				}
			} LA13: ;
		}
		TMP217 = mulInt64(b, sign);
		b = (NI64)(TMP217);
		TMP218 = subInt(i, start);
		result = (NI)(TMP218);
}	}
	LA10: ;
	return result;
}

N_NIMCALL(NI, npuParseBiggestInt)(NimStringDesc* s, NI64& number, NI start) {
	NI result;
	NI64 res;
	result = 0;
	res = 0;
	result = rawparseint_94914(s, res, start);
	number = res;
	return result;
}

static N_INLINE(void, nimFrame)(TFrame* s) {
	NI LOC1;
	LOC1 = 0;
	{
		if (!(frameptr_17042 == NIM_NIL)) goto LA4;
{		LOC1 = ((NI) 0);
}	}
	goto LA2;
	LA4: ;
	{
		LOC1 = ((NI) ((NI16)((*frameptr_17042).calldepth + ((NI16) 1))));
	}
	LA2: ;
	(*s).calldepth = ((NI16) (LOC1));
	(*s).prev = frameptr_17042;
	frameptr_17042 = s;
	{
		if (!((*s).calldepth == ((NI16) 2000))) goto LA9;
{		stackoverflow_19801();
}	}
	LA9: ;
}

static N_INLINE(void, popFrame)(void) {
	frameptr_17042 = (*frameptr_17042).prev;
}

static N_INLINE(Tcell46547*, usrtocell_50047)(void* usr) {
	Tcell46547* result;
	nimfr("usrToCell", "gc.nim")
	result = 0;
	nimln(118, "gc.nim");
	result = ((Tcell46547*) ((NI)((NU64)(((NI) (usr))) - (NU64)(((NI)sizeof(Tcell46547))))));
	popFrame();
	return result;
}

static N_INLINE(void, rtladdzct_51604)(Tcell46547* c) {
	nimfr("rtlAddZCT", "gc.nim")
	nimln(199, "gc.nim");
	addzct_50017(gch_48444.zct, c);
	popFrame();
}

static N_INLINE(void, nimGCunrefNoCycle)(void* p) {
	nimfr("nimGCunrefNoCycle", "gc.nim")
	nimln(233, "gc.nim");
	Tcell46547* c = usrtocell_50047(p);
	nimln(235, "gc.nim");
	{
		nimln(167, "gc.nim");
		(*c).refcount -= ((NI) 8);
		nimln(168, "gc.nim");
		if (!((NU64)((*c).refcount) < (NU64)(((NI) 8)))) goto LA3;
{		nimln(236, "gc.nim");
		rtladdzct_51604(c);
}	}
	LA3: ;
	popFrame();
}

N_NIMCALL(NI, npuParseInt)(NimStringDesc* s, NI& number, NI start) {
	NI result;
	NI64 res;
	result = 0;
	res = 0;
	result = npuParseBiggestInt(s, res, start);
	{
		NIM_BOOL LOC3;
		NIM_BOOL LOC5;
		Overflowerror3443* e_95055;
		NimStringDesc* LOC9;
		LOC3 = 0;
		LOC3 = NIM_FALSE;
		if (!(LOC3)) goto LA4;
		LOC5 = 0;
		LOC5 = (res < (IL64(-9223372036854775807) - IL64(1)));
		if (LOC5) goto LA6;
		LOC5 = (IL64(9223372036854775807) < res);
		LA6: ;
		LOC3 = LOC5;
		LA4: ;
		if (!LOC3) goto LA7;
{		e_95055 = 0;
		e_95055 = (Overflowerror3443*) newObj((&NTI23201), sizeof(Overflowerror3443));
		(*e_95055).m_type = (&NTI3443);
		LOC9 = 0;
		LOC9 = (*e_95055).message; (*e_95055).message = copyStringRC1(((NimStringDesc*) &TMP219));
		if (LOC9) nimGCunrefNoCycle(LOC9);
		raiseException((Exception*)e_95055, "OverflowError");
}	}
	goto LA1;
	LA7: ;
	{
		if (!!((result == ((NI) 0)))) goto LA11;
{		number = ((NI) (res));
}	}
	goto LA1;
	LA11: ;
	LA1: ;
	return result;
}
NIM_EXTERNC N_NOINLINE(void, stdlib_parseutilsInit)(void) {
}

NIM_EXTERNC N_NOINLINE(void, stdlib_parseutilsDatInit)(void) {
}
