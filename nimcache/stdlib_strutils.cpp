/* Generated by Nim Compiler v0.11.2 */
/*   (c) 2015 Andreas Rumpf */
/* The generated code is subject to the original license. */
/* Compiled for: Windows, amd64, gcc */
/* Command for C compiler:
   g++.exe -c  -w -w -fpermissive  -IC:\Nim\lib -o c:\users\dansm\desktop\folders\robotics\field-telemetry\nimcache\stdlib_strutils.o c:\users\dansm\desktop\folders\robotics\field-telemetry\nimcache\stdlib_strutils.cpp */
#define NIM_INTBITS 64
#include "nimbase.h"

#include <string.h>
struct NimStringDesc;
struct TGenericSeq;
struct Valueerror3449;
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
struct  Valueerror3449  : public Exception {
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
N_NIMCALL(NimStringDesc*, nimIntToStr)(NI x);
static N_INLINE(void, appendChar)(NimStringDesc* dest, NIM_CHAR c);
static N_INLINE(void, appendString)(NimStringDesc* dest, NimStringDesc* src);
N_NIMCALL(NimStringDesc*, rawNewString)(NI space);
N_NIMCALL(NimStringDesc*, mnewString)(NI len);
N_NIMCALL(NimStringDesc*, mnewString)(NI len);
N_NIMCALL(NI, npuParseInt)(NimStringDesc* s, NI& number, NI start);
N_NIMCALL(void*, newObj)(TNimType* typ, NI size);
static N_INLINE(void, asgnRefNoCycle)(void** dest, void* src);
static N_INLINE(Tcell46547*, usrtocell_50047)(void* usr);
static N_INLINE(void, nimFrame)(TFrame* s);
N_NOINLINE(void, stackoverflow_19801)(void);
static N_INLINE(void, popFrame)(void);
static N_INLINE(void, rtladdzct_51604)(Tcell46547* c);
N_NOINLINE(void, addzct_50017)(Tcellseq46563& s, Tcell46547* c);
N_NIMCALL(void, raiseException)(Exception* e, NCSTRING ename);
N_NIMCALL(NIM_CHAR, nsuToLowerChar)(NIM_CHAR c);
N_NIMCALL(NIM_CHAR, nsuToUpperChar)(NIM_CHAR c);
STRING_LITERAL(TMP220, "invalid integer: ", 17);
extern TNimType NTI22601; /* ref ValueError */
extern TNimType NTI3449; /* ValueError */
extern TFrame* frameptr_17042;
extern Tgcheap48416 gch_48444;

static N_INLINE(void, appendChar)(NimStringDesc* dest, NIM_CHAR c) {
	(*dest).data[((*dest).len)- 0] = c;
	(*dest).data[((NI)((*dest).len + ((NI) 1)))- 0] = 0;
	(*dest).len += ((NI) 1);
}

static N_INLINE(void, appendString)(NimStringDesc* dest, NimStringDesc* src) {
	memcpy(((NCSTRING) ((&(*dest).data[((*dest).len)- 0]))), ((NCSTRING) ((*src).data)), (NI)((*src).len + ((NI) 1)));
	(*dest).len += (*src).len;
}

N_NIMCALL(NimStringDesc*, nsuIntToStr)(NI x, NI minchars) {
	NimStringDesc* result;
	result = 0;
	result = nimIntToStr((x > 0? (x) : -(x)));
	{
		NI i_98462;
		NI HEX3Atmp_98464;
		i_98462 = 0;
		HEX3Atmp_98464 = 0;
		HEX3Atmp_98464 = (NI)(((NI) (minchars)) - (result ? result->len : 0));
		NI res_98467 = ((NI) 1);
		{
			while (1) {
				NimStringDesc* LOC4;
				if (!(res_98467 <= HEX3Atmp_98464)) goto LA3;
				i_98462 = res_98467;
				LOC4 = 0;
				LOC4 = rawNewString(result->len + 1);
appendChar(LOC4, 48);
appendString(LOC4, result);
				result = LOC4;
				res_98467 += ((NI) 1);
			} LA3: ;
		}
	}
	{
		NimStringDesc* LOC9;
		if (!(x < ((NI) 0))) goto LA7;
{		LOC9 = 0;
		LOC9 = rawNewString(result->len + 1);
appendChar(LOC9, 45);
appendString(LOC9, result);
		result = LOC9;
}	}
	LA7: ;
	return result;
}

N_NIMCALL(NimStringDesc*, nsuRepeatChar)(NIM_CHAR c, NI count) {
	NimStringDesc* result;
	result = 0;
	result = mnewString(count);
	{
		NI i_98773;
		NI HEX3Atmp_98775;
		i_98773 = 0;
		HEX3Atmp_98775 = 0;
		HEX3Atmp_98775 = (NI)(((NI) (count)) - ((NI) 1));
		NI res_98778 = ((NI) 0);
		{
			while (1) {
				if (!(res_98778 <= ((NI) (HEX3Atmp_98775)))) goto LA3;
				i_98773 = ((NI) (res_98778));
				result->data[i_98773] = c;
				res_98778 += ((NI) 1);
			} LA3: ;
		}
	}
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

static N_INLINE(void, asgnRefNoCycle)(void** dest, void* src) {
	nimfr("asgnRefNoCycle", "gc.nim")
	nimln(251, "gc.nim");
	{
		if (!!((src == NIM_NIL))) goto LA3;
{		nimln(252, "gc.nim");
		Tcell46547* c = usrtocell_50047(src);
		nimln(169, "gc.nim");
		(*c).refcount += ((NI) 8);
}	}
	LA3: ;
	nimln(254, "gc.nim");
	{
		if (!!(((*dest) == NIM_NIL))) goto LA7;
{		nimln(255, "gc.nim");
		Tcell46547* c = usrtocell_50047((*dest));
		nimln(256, "gc.nim");
		{
			nimln(167, "gc.nim");
			(*c).refcount -= ((NI) 8);
			nimln(168, "gc.nim");
			if (!((NU64)((*c).refcount) < (NU64)(((NI) 8)))) goto LA11;
{			nimln(257, "gc.nim");
			rtladdzct_51604(c);
}		}
		LA11: ;
}	}
	LA7: ;
	nimln(258, "gc.nim");
	(*dest) = src;
	popFrame();
}

N_NIMCALL(NI, nsuParseInt)(NimStringDesc* s) {
	NI result;
	result = 0;
	NI L = npuParseInt(s, result, ((NI) 0));
	{
		NIM_BOOL LOC3;
		Valueerror3449* e_98494;
		NimStringDesc* LOC7;
		LOC3 = 0;
		LOC3 = !((L == (s ? s->len : 0)));
		if (LOC3) goto LA4;
		LOC3 = (L == ((NI) 0));
		LA4: ;
		if (!LOC3) goto LA5;
{		e_98494 = 0;
		e_98494 = (Valueerror3449*) newObj((&NTI22601), sizeof(Valueerror3449));
		(*e_98494).m_type = (&NTI3449);
		LOC7 = 0;
		LOC7 = rawNewString(s->len + 17);
appendString(LOC7, ((NimStringDesc*) &TMP220));
appendString(LOC7, s);
		asgnRefNoCycle((void**) (&(*e_98494).message), LOC7);
		raiseException((Exception*)e_98494, "ValueError");
}	}
	LA5: ;
	return result;
}

N_NIMCALL(NIM_CHAR, nsuToLowerChar)(NIM_CHAR c) {
	NIM_CHAR result;
	result = 0;
	{
		if (!(((NU8)(c)) >= ((NU8)(65)) && ((NU8)(c)) <= ((NU8)(90)))) goto LA3;
{		result = ((NIM_CHAR) (((NI) ((NI)(((NI) (((NU8)(c)))) + ((NI) 32))))));
}	}
	goto LA1;
	LA3: ;
	{
		result = c;
	}
	LA1: ;
	return result;
}

N_NIMCALL(NimStringDesc*, nsuToLowerStr)(NimStringDesc* s) {
	NimStringDesc* result;
	result = 0;
	result = mnewString(((NI) ((s ? s->len : 0))));
	{
		NI i_97091;
		NI HEX3Atmp_97093;
		i_97091 = 0;
		HEX3Atmp_97093 = 0;
		HEX3Atmp_97093 = (NI)((s ? s->len : 0) - ((NI) 1));
		NI res_97096 = ((NI) 0);
		{
			while (1) {
				if (!(res_97096 <= HEX3Atmp_97093)) goto LA3;
				i_97091 = res_97096;
				result->data[i_97091] = nsuToLowerChar(s->data[i_97091]);
				res_97096 += ((NI) 1);
			} LA3: ;
		}
	}
	return result;
}

N_NIMCALL(NI, nsuCmpIgnoreCase)(NimStringDesc* a, NimStringDesc* b) {
	NI result;
{	result = 0;
	NI i = ((NI) 0);
	NI m = (((a ? a->len : 0) <= (b ? b->len : 0)) ? (a ? a->len : 0) : (b ? b->len : 0));
	{
		while (1) {
			NIM_CHAR LOC3;
			NIM_CHAR LOC4;
			if (!(i < m)) goto LA2;
			LOC3 = 0;
			LOC3 = nsuToLowerChar(a->data[i]);
			LOC4 = 0;
			LOC4 = nsuToLowerChar(b->data[i]);
			result = (NI)(((NI) (((NU8)(LOC3)))) - ((NI) (((NU8)(LOC4)))));
			{
				if (!!((result == ((NI) 0)))) goto LA7;
{				goto BeforeRet;
}			}
			LA7: ;
			i += ((NI) 1);
		} LA2: ;
	}
	result = (NI)((a ? a->len : 0) - (b ? b->len : 0));
	}BeforeRet: ;
	return result;
}

N_NIMCALL(NIM_CHAR, nsuToUpperChar)(NIM_CHAR c) {
	NIM_CHAR result;
	result = 0;
	{
		if (!(((NU8)(c)) >= ((NU8)(97)) && ((NU8)(c)) <= ((NU8)(122)))) goto LA3;
{		result = ((NIM_CHAR) (((NI) ((NI)(((NI) (((NU8)(c)))) - ((NI) 32))))));
}	}
	goto LA1;
	LA3: ;
	{
		result = c;
	}
	LA1: ;
	return result;
}

N_NIMCALL(NimStringDesc*, nsuToUpperStr)(NimStringDesc* s) {
	NimStringDesc* result;
	result = 0;
	result = mnewString(((NI) ((s ? s->len : 0))));
	{
		NI i_97177;
		NI HEX3Atmp_97179;
		i_97177 = 0;
		HEX3Atmp_97179 = 0;
		HEX3Atmp_97179 = (NI)((s ? s->len : 0) - ((NI) 1));
		NI res_97182 = ((NI) 0);
		{
			while (1) {
				if (!(res_97182 <= HEX3Atmp_97179)) goto LA3;
				i_97177 = res_97182;
				result->data[i_97177] = nsuToUpperChar(s->data[i_97177]);
				res_97182 += ((NI) 1);
			} LA3: ;
		}
	}
	return result;
}
NIM_EXTERNC N_NOINLINE(void, stdlib_strutilsInit)(void) {
}

NIM_EXTERNC N_NOINLINE(void, stdlib_strutilsDatInit)(void) {
}

