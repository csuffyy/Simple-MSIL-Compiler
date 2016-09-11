/* 
CC386 C Compiler
Copyright 1994-2011 David Lindauer.

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

This program is derived from the cc68k complier by 
Matthew Brandt (mailto::mattb@walkingdog.net) 

You may contact the author of this derivative at:

mailto::camille@bluegrass.net
 */
/* known errors */

#define ERR_ILLCHAR     1
#define ERR_NEEDCHAR    2
#define ERR_NEEDCONST   3
#define ERR_FPCON       4
#define ERR_IDEXPECT    5
#define ERR_IDENTEXPECT 6
#define ERR_UNEXPECT	7
#define ERR_PUNCT       8
#define ERR_INSERT	9
#define ERR_UNDEFINED   10
#define ERR_DUPSYM      11
#define ERR_NOINIT      12
#define ERR_INITSIZE    13
#define ERR_NOCASE      14
#define ERR_DUPCASE     15
#define ERR_LABEL       16
#define ERR_ELSE	17
#define ERR_EXPREXPECT  18
#define ERR_ILLCLASS    19
#define ERR_ILLCLASS2   20
#define ERR_NOPOINTER   21
#define ERR_NOFUNC      22
#define ERR_LVALUE      23
#define ERR_DEREF       24
#define ERR_ILLCAST	25
#define ERR_PREPROCID   26
#define ERR_INCLFILE    27
#define ERR_CANTOPEN    28
#define ERR_PREPROCMATCH 29
#define ERR_MACROSUBS   30
#define ERR_ARGMISMATCH 31
#define ERR_ARGLENSHORT 32
#define ERR_ARGLENLONG  33
#define ERR_CALLMISMATCH 34
#define ERR_CALLLENSHORT 35
#define ERR_CALLLENLONG  36
#define ERR_DECLMISMATCH 37
#define ERR_RETMISMATCH 38
#define ERR_MISMATCH    39
#define ERR_ARRAYMISMATCH 40
#define ERR_ILLTYPE	41
#define ERR_DECLEXPECT  42
#define ERR_INVFLOAT	43
#define ERR_INVTRAP	44
#define ERR_BFILLEGAL	45
#define ERR_BFTOOBIG	46
#define ERR_ERROR	47	/* User error */
#define ERR_BFTYPE	48	/* Bit field non-scalar */
#define ERR_INTERP	49
#define ERR_BFADDR	50
#define ERR_MODCONS	51
#define ERR_SZTYPE	52
#define ERR_FUNCRETVAL 53
#define ERR_SYMUNUSED	54
#define ERR_SYMUNDEF	55
#define ERR_SYMASSIGNED 56
#define ERR_NONPORT	57
#define ERR_UNREACHABLE 58
#define ERR_FUNCUNUSED	59
#define ERR_CODENONE	60
#define ERR_BADEQUATE	61
#define ERR_NOANDREG 	62
#define ERR_NOCONTINUE  63
#define ERR_DUPLABEL    64
#define ERR_NOFUNCARRAY 65
#define ERR_NOVOIDRET   66
#define ERR_ZEROSTORAGE 67
#define ERR_SHORTPOINTER 68
#define ERR_NOSTATICFUNC 69
#define ERR_UNUSEDLABEL	70											
#define ERR_NOPROTO     71
#define ERR_LOSTCONV    72
#define ERR_UNDEFLABEL	73
#define ERR_ILLREGISTER 74
#define ERR_SUPERAND	75
#define ERR_STATICSYMUNUSED 76
#define ERR_NODECLARE	 77
#define ERR_ZEROPTR	78
#define ERR_NOMAIN 79
#define ERR_NOREF 80
#define ERR_CANTREF 81
#define ERR_TEMPUSED 82
#define ERR_REFMUSTINIT 83
#define ERR_TEMPINIT 84
#define ERR_REFLVALUE 85
#define ERR_REFNOCONS 86
#define ERR_MISSINGDEFAULT 87
#define ERR_AMBIGFUNC 88
#define ERR_NOLOCALDEFAULT 89
#define ERR_CPPMISMATCH 90
#define ERR_NOOVERMAIN 91
#define ERR_SWITCHINT 92
#define ERR_NOFUNCMATCH 93
#define ERR_PREDEFSTRUCT 94
#define ERR_LOCALCLASS 95
#define ERR_PUREDECL 96
#define ERR_BADESTRUCT 97
#define ERR_TYPECONSTRUCT 98
#define ERR_NOTYPEQUAL 99
#define ERR_NOTACLASS 100
#define ERR_SIZE 101
#define ERR_NEVERSTRUCT 102
#define ERR_LONGLONG 103
#define ERR_UPDOWN 104
#define ERR_INTBITFIELDS 105
#define ERR_COMMENTMATCH 106
#define ERR_PASCAL_NO_ELLIPSE 107
#define ERR_PASCAL_NO_INT 108
#define ERR_SUSPICIOUS 109
#define ERR_NOFUNCSTRUCT 110
#define ERR_STRINGTOOBIG 111
#define ERR_CONSTTOOLARGE 112
#define ERR_MULTIPLEINIT 113
#define ERR_INVALIDSTRING 114
#define ERR_AMODEEXPECT 115
#define ERR_ASCALE      116
#define ERR_AINVINDXMODE 117
#define ERR_AILLADDRESS  118
#define ERR_ATOOMANYSPECS 119
#define ERR_ATOOMANYSEGS 120
#define ERR_AINVOP       121
#define ERR_AINVSIZE       122
#define ERR_AUSELEA 123
#define ERR_ALABEXPECT 124
#define ERR_ANEEDFP 125
#define ERR_AINVSELPROC 126
#define ERR_ATOOMANYREGS 127
#define ERR_AAREGEXPECT 128
#define ERR_PREPIG 129
#define ERR_ANEEDAD 130
#define ERR_AREGMISMATCH 131
#define ERR_CHAR4CHAR 132
#define ERR_LOSTCONVCASE 133
#define ERR_PARAMUNUSED 134
#define ERR_TYPEQUALEXP 135
#define ERR_VIRTFUNC 136
#define ERR_CONSFUNC 137
#define ERR_CANTHAVETYPE 138
#define ERR_NODESTRUCTARG 139
#define ERR_NODESTRUCTQUAL 140
#define ERR_TYPENAMEEXP 141
#define ERR_BASESTRUCTCLASS 142
#define ERR_NOTACCESSIBLE 143
#define ERR_LOCALCLASSNOFUNC 144
#define ERR_NOBASECONS 145
#define ERR_CONSDECLNOMATCH 146
#define ERR_CONSNOREFINIT 147
#define ERR_STATICNOTHIS 148
#define ERR_NOCLASSNOTHIS 149
#define ERR_OLDFUNCSTYLE 150
#define ERR_MAINNOPTR 151
#define ERR_CLASSINSTDOTSTAR 152
#define ERR_MEMBERPTRMISMATCH 153
#define ERR_NOASSIGNCOMPLEXMEMBERPTR 154
#define ERR_NOLOCALNAMESPACE 155
#define ERR_NAMESPACEEXP 156
#define ERR_NOADDRMEMBERPTR 157
#define ERR_ILLSTRUCT 158
#define ERR_UNIONNOVIRT 159
#define ERR_NOCLASSMEMBERFUNC 160
#define ERR_NOINTRINSFOUND 161
#define ERR_NOVOID 162
#define ERR_UNIONNOBASE 163
#define ERR_STATICNOACCESS 164
#define ERR_NONSTATICMUSTCLASS 165
#define ERR_POINTTOSTRUCT 166
#define ERR_ADDROFSTRUCT 167
#define ERR_MEMBERNAMEEXP 168
#define ERR_MUSTCALLMEMBER 169
#define ERR_OPERATOREXPECTED 170
#define ERR_OPERATORMUSTCLASS 171
#define ERR_CONSTNOMEMBER 172
#define ERR_USERERR 173
#define ERR_USERWARN 174
#define ERR_DECL0ARG 175
#define ERR_DECL1ARG 176
#define ERR_DECL2ARG 177
#define ERR_SIZE_T_NEW 178
#define ERR_VOIDSTAR_NEW 179
#define ERR_VOIDSTAR_DELETE 180
#define ERR_VOID_DELETE 181
#define ERR_OPMUSTBEMEMBER 182
#define ERR_POINTTOCLASS 183
#define ERR_OVPOSTFIXINTLAST 184
#define ERR_NOREFARRAY 185
#define ERR_AMBIGCONTEXT 186
#define ERR_WRONGMACROARGS 187
#define ERR_OBJECTNEEDED 188
#define ERR_NOSTATIC 189
#define ERR_ILLINIT 190
#define ERR_NOTUNAMBIGUOUSBASE 191
#define ERR_NOINITSTATICMEMBER 192
#define ERR_MEMBERREINIT 193
#define ERR_NEWARRAYINIT 194
#define ERR_VOIDFUNCNOVALUE 195
#define ERR_FRIENDMUSTCLASS 196
#define ERR_FRIENDNEEDFUNC 197
#define ERR_FRIENDCLASSNEEDSTRUC 198
#define ERR_ADDRMEMORYLOC 199
#define ERR_INVCONST 200
#define ERR_SUSPICIOUSCONST 201
#define ERR_INVALIDTEMPLATE 202
#define ERR_TEMPLATECLASSFUNC 203
#define ERR_TEMPLATEEOF 204
#define ERR_DECLARATIONCOMMA 205
#define ERR_TEMPLATENOINSTANTIATION 206
#define ERR_INCOMPATTYPECONV 207
#define ERR_TEMPLATEBODYDECLARED 208
#define ERR_TEMPLATEEXTRAARG 209
#define ERR_TEMPLATEFEWARG 210
#define ERR_ILLEGALNAMESPACEUSE 211
#define ERR_NOTNSORTYPQUAL 212
#define ERR_INVALIDARGTOTYPEOF 213
#define ERR_TEMPLATEFUNCMATCHCLASS 214
#define ERR_EXPMEMBERPTRFUNC 215
#define ERR_NOTPUBLICBASECLASS 216
#define ERR_ALSOBASECLASS 217
#define ERR_MEMBERSAMENAME 218
#define ERR_CONSTMUSTINIT 219
#define ERR_TYPENOVIRTFUNC 220
#define ERR_NOXCEPT 221
#define ERR_STRUCTEXP 222
#define ERR_CATCHEXP 223
#define ERR_ELLIPSEHANDLERLAST 224
#define ERR_DUPHANDLER 225
#define ERR_CANTRESOLVE 226
#define ERR_TYPEINFOUNDEF 227
#define ERR_DECLNOTALLOWED 228
#define ERR_OPERATORNOTDEFINED 229
#define ERR_REDECLDEFAULT 230
#define ERR_OBJMEMPTRREQ 231
#define ERR_REDEFINE 232
#define ERR_AMBIGTEMPLATE 233
#define ERR_SIMPLETEMPLATEARGS 234
#define ERR_SPECIALIZATION 235
#define ERR_EXPLICITNOTALLOWED 236
#define ERR_NOEXPLICITHERE 237
#define ERR_RETURNLOCAL 238
#define ERR_REDEFTEMPLATEDEFAULTS 239
#define ERR_TEMPLATEDEFAULTLIMITED 240
#define ERR_NEEDSPECIAL 241
#define ERR_NEEDSTRING 242
#define ERR_CONSTNOCONS 243
#define ERR_CONSNOCONSTINIT 244
#define ERR_DECL1OR2ARG 245
#define ERR_DECL0OR1ARG 246
#define ERR_PARAMMISSINGNAME 247
#define ERR_FLEXARRAYLAST 248
#define ERR_VLABLOCKSCOPE 249
#define ERR_RESTRICTPTR 250
#define ERR_MAINNOINLINE 251
#define ERR_INLINENOSTATIC 252
#define ERR_VMSTATIC 253
#define ERR_VLAMUSTSIZE 254
#define ERR_DEFINEENUM 255
#define ERR_INLINEFUNC 256
#define ERR_ARRELEMSIZE 257
#define ERR_SELECTSCALAR 258
#define ERR_VLAGOTO 259
#define ERR_FUNCRETVAL2 260
#define ERR_EXTRAIDENT 261
#define ERR_FUNCBADRET 262
#define ERR_ILLUSEPTR 263
#define ERR_ILLPTRADD 264
#define ERR_INVPTRSUB 265
#define ERR_HASDEF  266
#define ERR_CASENOSWITCH 267
#define ERR_INLINENOBODY 268
#define ERR_DUPVIRTUAL 269
#define ERR_BITNOINITIALVALUE 270
#define ERR_ALLOCA 271
#define ERR_NONESTEDFUNC 272
#define ERR_WARNING 273
#define ERR_C99_KEYWORD 274
#define ERR_TYPE_C99 275
#define ERR_VLA_c99 276
#define ERR_ARRAY_QUALIFIERS_C99 277
#define ERR_C99_STYLE_INITIALIZATION_USED 278
#define ERR_C99_NON_CONSTANT_INITIALIZATION 279
#define ERR_C99_FLEXIBLE_ARRAY 280
#define ERR_C99_VARIABLE_MACRO_ARGS 281
#define ERR_NESTEDCOMMENT 282
#define ERR_MAX 283
