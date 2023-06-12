//------------------------------------------------------------------------------
//
//    Copyright (C) Streamlet. All rights reserved.
//
//    File Name:   xlMacros.h
//    Author:      Streamlet
//    Create Time: 2011-01-12
//    Description:
//
//------------------------------------------------------------------------------

#ifndef __XLMACROS_H_83436072_95E5_4500_A129_49EBFD0899E5_INCLUDED__
#define __XLMACROS_H_83436072_95E5_4500_A129_49EBFD0899E5_INCLUDED__

#include "../../xlDef.h"

namespace xl
{
#define XL_NIL
#define XL_LPARE    (
#define XL_RPARE    )
#define XL_COMMA    ,
#define XL_VAL(s)   s

#define XL_CONN_(s, t)  s##t
#define XL_CONN(s, t)   XL_CONN_(s, t)

#define XL_TOSTR_(s)    #s
#define XL_TOSTR(s)     XL_TOSTR_(s)
#define XL_TOWCS(s)     XL_CONN(L, XL_TOSTR(s))

#define XL_EVAL_(...) __VA_ARGS__
#define XL_EVAL(f, p)  XL_EVAL_(f XL_LPARE p XL_RPARE)

#define XL_INC_0    1
#define XL_INC_1    2
#define XL_INC_2    3
#define XL_INC_3    4
#define XL_INC_4    5
#define XL_INC_5    6
#define XL_INC_6    7
#define XL_INC_7    8
#define XL_INC_8    9
#define XL_INC_9    10
#define XL_INC_10   11
#define XL_INC_11   12
#define XL_INC_12   13
#define XL_INC_13   14
#define XL_INC_14   15
#define XL_INC_15   16
#define XL_INC_16   17
#define XL_INC_17   18
#define XL_INC_18   19
#define XL_INC_19   20
#define XL_INC_20   21
#define XL_INC_21   22
#define XL_INC_22   23
#define XL_INC_23   24
#define XL_INC_24   25
#define XL_INC_25   26
#define XL_INC_26   27
#define XL_INC_27   28
#define XL_INC_28   29
#define XL_INC_29   30
#define XL_INC_30   31
#define XL_INC_31   32
#define XL_INC_32   33
#define XL_INC_33   34
#define XL_INC_34   35
#define XL_INC_35   36
#define XL_INC_36   37
#define XL_INC_37   38
#define XL_INC_38   39
#define XL_INC_39   40
#define XL_INC_40   41
#define XL_INC_41   42
#define XL_INC_42   43
#define XL_INC_43   44
#define XL_INC_44   45
#define XL_INC_45   46
#define XL_INC_46   47
#define XL_INC_47   48
#define XL_INC_48   49
#define XL_INC_49   50
#define XL_INC_50   51
#define XL_INC_51   52
#define XL_INC_52   53
#define XL_INC_53   54
#define XL_INC_54   55
#define XL_INC_55   56
#define XL_INC_56   57
#define XL_INC_57   58
#define XL_INC_58   59
#define XL_INC_59   60
#define XL_INC_60   61
#define XL_INC_61   62
#define XL_INC_62   63
#define XL_INC_63   64
#define XL_INC_64   65
#define XL_INC_65   66
#define XL_INC_66   67
#define XL_INC_67   68
#define XL_INC_68   69
#define XL_INC_69   70
#define XL_INC_70   71
#define XL_INC_71   72
#define XL_INC_72   73
#define XL_INC_73   74
#define XL_INC_74   75
#define XL_INC_75   76
#define XL_INC_76   77
#define XL_INC_77   78
#define XL_INC_78   79
#define XL_INC_79   80
#define XL_INC_80   81
#define XL_INC_81   82
#define XL_INC_82   83
#define XL_INC_83   84
#define XL_INC_84   85
#define XL_INC_85   86
#define XL_INC_86   87
#define XL_INC_87   88
#define XL_INC_88   89
#define XL_INC_89   90
#define XL_INC_90   91
#define XL_INC_91   92
#define XL_INC_92   93
#define XL_INC_93   94
#define XL_INC_94   95
#define XL_INC_95   96
#define XL_INC_96   97
#define XL_INC_97   98
#define XL_INC_98   99
#define XL_INC_99

#define XL_INC(n)   XL_CONN(XL_INC_, n)

#define XL_DEC_0
#define XL_DEC_1    0
#define XL_DEC_2    1
#define XL_DEC_3    2
#define XL_DEC_4    3
#define XL_DEC_5    4
#define XL_DEC_6    5
#define XL_DEC_7    6
#define XL_DEC_8    7
#define XL_DEC_9    8
#define XL_DEC_10   9
#define XL_DEC_11   10
#define XL_DEC_12   11
#define XL_DEC_13   12
#define XL_DEC_14   13
#define XL_DEC_15   14
#define XL_DEC_16   15
#define XL_DEC_17   16
#define XL_DEC_18   17
#define XL_DEC_19   18
#define XL_DEC_20   19
#define XL_DEC_21   20
#define XL_DEC_22   21
#define XL_DEC_23   22
#define XL_DEC_24   23
#define XL_DEC_25   24
#define XL_DEC_26   25
#define XL_DEC_27   26
#define XL_DEC_28   27
#define XL_DEC_29   28
#define XL_DEC_30   29
#define XL_DEC_31   30
#define XL_DEC_32   31
#define XL_DEC_33   32
#define XL_DEC_34   33
#define XL_DEC_35   34
#define XL_DEC_36   35
#define XL_DEC_37   36
#define XL_DEC_38   37
#define XL_DEC_39   38
#define XL_DEC_40   39
#define XL_DEC_41   40
#define XL_DEC_42   41
#define XL_DEC_43   42
#define XL_DEC_44   43
#define XL_DEC_45   44
#define XL_DEC_46   45
#define XL_DEC_47   46
#define XL_DEC_48   47
#define XL_DEC_49   48
#define XL_DEC_50   49
#define XL_DEC_51   50
#define XL_DEC_52   51
#define XL_DEC_53   52
#define XL_DEC_54   53
#define XL_DEC_55   54
#define XL_DEC_56   55
#define XL_DEC_57   56
#define XL_DEC_58   57
#define XL_DEC_59   58
#define XL_DEC_60   59
#define XL_DEC_61   60
#define XL_DEC_62   61
#define XL_DEC_63   62
#define XL_DEC_64   63
#define XL_DEC_65   64
#define XL_DEC_66   65
#define XL_DEC_67   66
#define XL_DEC_68   67
#define XL_DEC_69   68
#define XL_DEC_70   69
#define XL_DEC_71   70
#define XL_DEC_72   71
#define XL_DEC_73   72
#define XL_DEC_74   73
#define XL_DEC_75   74
#define XL_DEC_76   75
#define XL_DEC_77   76
#define XL_DEC_78   77
#define XL_DEC_79   78
#define XL_DEC_80   79
#define XL_DEC_81   80
#define XL_DEC_82   81
#define XL_DEC_83   82
#define XL_DEC_84   83
#define XL_DEC_85   84
#define XL_DEC_86   85
#define XL_DEC_87   86
#define XL_DEC_88   87
#define XL_DEC_89   88
#define XL_DEC_90   89
#define XL_DEC_91   90
#define XL_DEC_92   91
#define XL_DEC_93   92
#define XL_DEC_94   93
#define XL_DEC_95   94
#define XL_DEC_96   95
#define XL_DEC_97   96
#define XL_DEC_98   97
#define XL_DEC_99   98

#define XL_DEC(n)   XL_CONN(XL_DEC_, n)

#define XL_BOOL_0       F
#define XL_BOOL_1       T
#define XL_BOOL_2       T
#define XL_BOOL_3       T
#define XL_BOOL_4       T
#define XL_BOOL_5       T
#define XL_BOOL_6       T
#define XL_BOOL_7       T
#define XL_BOOL_8       T
#define XL_BOOL_9       T
#define XL_BOOL_10      T
#define XL_BOOL_11      T
#define XL_BOOL_12      T
#define XL_BOOL_13      T
#define XL_BOOL_14      T
#define XL_BOOL_15      T
#define XL_BOOL_16      T
#define XL_BOOL_17      T
#define XL_BOOL_18      T
#define XL_BOOL_19      T
#define XL_BOOL_20      T
#define XL_BOOL_21      T
#define XL_BOOL_22      T
#define XL_BOOL_23      T
#define XL_BOOL_24      T
#define XL_BOOL_25      T
#define XL_BOOL_26      T
#define XL_BOOL_27      T
#define XL_BOOL_28      T
#define XL_BOOL_29      T
#define XL_BOOL_30      T
#define XL_BOOL_31      T
#define XL_BOOL_32      T
#define XL_BOOL_33      T
#define XL_BOOL_34      T
#define XL_BOOL_35      T
#define XL_BOOL_36      T
#define XL_BOOL_37      T
#define XL_BOOL_38      T
#define XL_BOOL_39      T
#define XL_BOOL_40      T
#define XL_BOOL_41      T
#define XL_BOOL_42      T
#define XL_BOOL_43      T
#define XL_BOOL_44      T
#define XL_BOOL_45      T
#define XL_BOOL_46      T
#define XL_BOOL_47      T
#define XL_BOOL_48      T
#define XL_BOOL_49      T
#define XL_BOOL_50      T
#define XL_BOOL_51      T
#define XL_BOOL_52      T
#define XL_BOOL_53      T
#define XL_BOOL_54      T
#define XL_BOOL_55      T
#define XL_BOOL_56      T
#define XL_BOOL_57      T
#define XL_BOOL_58      T
#define XL_BOOL_59      T
#define XL_BOOL_60      T
#define XL_BOOL_61      T
#define XL_BOOL_62      T
#define XL_BOOL_63      T
#define XL_BOOL_64      T
#define XL_BOOL_65      T
#define XL_BOOL_66      T
#define XL_BOOL_67      T
#define XL_BOOL_68      T
#define XL_BOOL_69      T
#define XL_BOOL_70      T
#define XL_BOOL_71      T
#define XL_BOOL_72      T
#define XL_BOOL_73      T
#define XL_BOOL_74      T
#define XL_BOOL_75      T
#define XL_BOOL_76      T
#define XL_BOOL_77      T
#define XL_BOOL_78      T
#define XL_BOOL_79      T
#define XL_BOOL_80      T
#define XL_BOOL_81      T
#define XL_BOOL_82      T
#define XL_BOOL_83      T
#define XL_BOOL_84      T
#define XL_BOOL_85      T
#define XL_BOOL_86      T
#define XL_BOOL_87      T
#define XL_BOOL_88      T
#define XL_BOOL_89      T
#define XL_BOOL_90      T
#define XL_BOOL_91      T
#define XL_BOOL_92      T
#define XL_BOOL_93      T
#define XL_BOOL_94      T
#define XL_BOOL_95      T
#define XL_BOOL_96      T
#define XL_BOOL_97      T
#define XL_BOOL_98      T
#define XL_BOOL_99      T

#define XL_TO_BOOL(i)   XL_CONN(XL_BOOL_, i)

#define XL_IFF_C_T(t)   t
#define XL_IFF_C_F(t)
#define XL_IFF(c, t)    XL_CONN(XL_IFF_C_, XL_TO_BOOL(c))(t)

#define XL_IF_C_T(t, e) t
#define XL_IF_C_F(t, e) e
#define XL_IF(c, t, e)  XL_CONN(XL_IF_C_, XL_TO_BOOL(c))(t, e)

#define XL_REP_0(m, ...)
#define XL_REP_1(m, ...)    m(1)
#define XL_REP_2(m, ...)    XL_REP_1(m, __VA_ARGS__) __VA_ARGS__ m(2)
#define XL_REP_3(m, ...)    XL_REP_2(m, __VA_ARGS__) __VA_ARGS__ m(3)
#define XL_REP_4(m, ...)    XL_REP_3(m, __VA_ARGS__) __VA_ARGS__ m(4)
#define XL_REP_5(m, ...)    XL_REP_4(m, __VA_ARGS__) __VA_ARGS__ m(5)
#define XL_REP_6(m, ...)    XL_REP_5(m, __VA_ARGS__) __VA_ARGS__ m(6)
#define XL_REP_7(m, ...)    XL_REP_6(m, __VA_ARGS__) __VA_ARGS__ m(7)
#define XL_REP_8(m, ...)    XL_REP_7(m, __VA_ARGS__) __VA_ARGS__ m(8)
#define XL_REP_9(m, ...)    XL_REP_8(m, __VA_ARGS__) __VA_ARGS__ m(9)
#define XL_REP_10(m, ...)   XL_REP_9(m, __VA_ARGS__) __VA_ARGS__ m(10)
#define XL_REP_11(m, ...)   XL_REP_10(m, __VA_ARGS__) __VA_ARGS__ m(11)
#define XL_REP_12(m, ...)   XL_REP_11(m, __VA_ARGS__) __VA_ARGS__ m(12)
#define XL_REP_13(m, ...)   XL_REP_12(m, __VA_ARGS__) __VA_ARGS__ m(13)
#define XL_REP_14(m, ...)   XL_REP_13(m, __VA_ARGS__) __VA_ARGS__ m(14)
#define XL_REP_15(m, ...)   XL_REP_14(m, __VA_ARGS__) __VA_ARGS__ m(15)
#define XL_REP_16(m, ...)   XL_REP_15(m, __VA_ARGS__) __VA_ARGS__ m(16)
#define XL_REP_17(m, ...)   XL_REP_16(m, __VA_ARGS__) __VA_ARGS__ m(17)
#define XL_REP_18(m, ...)   XL_REP_17(m, __VA_ARGS__) __VA_ARGS__ m(18)
#define XL_REP_19(m, ...)   XL_REP_18(m, __VA_ARGS__) __VA_ARGS__ m(19)
#define XL_REP_20(m, ...)   XL_REP_19(m, __VA_ARGS__) __VA_ARGS__ m(20)
#define XL_REP_21(m, ...)   XL_REP_20(m, __VA_ARGS__) __VA_ARGS__ m(21)
#define XL_REP_22(m, ...)   XL_REP_21(m, __VA_ARGS__) __VA_ARGS__ m(22)
#define XL_REP_23(m, ...)   XL_REP_22(m, __VA_ARGS__) __VA_ARGS__ m(23)
#define XL_REP_24(m, ...)   XL_REP_23(m, __VA_ARGS__) __VA_ARGS__ m(24)
#define XL_REP_25(m, ...)   XL_REP_24(m, __VA_ARGS__) __VA_ARGS__ m(25)
#define XL_REP_26(m, ...)   XL_REP_25(m, __VA_ARGS__) __VA_ARGS__ m(26)
#define XL_REP_27(m, ...)   XL_REP_26(m, __VA_ARGS__) __VA_ARGS__ m(27)
#define XL_REP_28(m, ...)   XL_REP_27(m, __VA_ARGS__) __VA_ARGS__ m(28)
#define XL_REP_29(m, ...)   XL_REP_28(m, __VA_ARGS__) __VA_ARGS__ m(29)
#define XL_REP_30(m, ...)   XL_REP_29(m, __VA_ARGS__) __VA_ARGS__ m(30)
#define XL_REP_31(m, ...)   XL_REP_30(m, __VA_ARGS__) __VA_ARGS__ m(31)
#define XL_REP_32(m, ...)   XL_REP_31(m, __VA_ARGS__) __VA_ARGS__ m(32)
#define XL_REP_33(m, ...)   XL_REP_32(m, __VA_ARGS__) __VA_ARGS__ m(33)
#define XL_REP_34(m, ...)   XL_REP_33(m, __VA_ARGS__) __VA_ARGS__ m(34)
#define XL_REP_35(m, ...)   XL_REP_34(m, __VA_ARGS__) __VA_ARGS__ m(35)
#define XL_REP_36(m, ...)   XL_REP_35(m, __VA_ARGS__) __VA_ARGS__ m(36)
#define XL_REP_37(m, ...)   XL_REP_36(m, __VA_ARGS__) __VA_ARGS__ m(37)
#define XL_REP_38(m, ...)   XL_REP_37(m, __VA_ARGS__) __VA_ARGS__ m(38)
#define XL_REP_39(m, ...)   XL_REP_38(m, __VA_ARGS__) __VA_ARGS__ m(39)
#define XL_REP_40(m, ...)   XL_REP_39(m, __VA_ARGS__) __VA_ARGS__ m(40)
#define XL_REP_41(m, ...)   XL_REP_40(m, __VA_ARGS__) __VA_ARGS__ m(41)
#define XL_REP_42(m, ...)   XL_REP_41(m, __VA_ARGS__) __VA_ARGS__ m(42)
#define XL_REP_43(m, ...)   XL_REP_42(m, __VA_ARGS__) __VA_ARGS__ m(43)
#define XL_REP_44(m, ...)   XL_REP_43(m, __VA_ARGS__) __VA_ARGS__ m(44)
#define XL_REP_45(m, ...)   XL_REP_44(m, __VA_ARGS__) __VA_ARGS__ m(45)
#define XL_REP_46(m, ...)   XL_REP_45(m, __VA_ARGS__) __VA_ARGS__ m(46)
#define XL_REP_47(m, ...)   XL_REP_46(m, __VA_ARGS__) __VA_ARGS__ m(47)
#define XL_REP_48(m, ...)   XL_REP_47(m, __VA_ARGS__) __VA_ARGS__ m(48)
#define XL_REP_49(m, ...)   XL_REP_48(m, __VA_ARGS__) __VA_ARGS__ m(49)
#define XL_REP_50(m, ...)   XL_REP_49(m, __VA_ARGS__) __VA_ARGS__ m(50)
#define XL_REP_51(m, ...)   XL_REP_50(m, __VA_ARGS__) __VA_ARGS__ m(51)
#define XL_REP_52(m, ...)   XL_REP_51(m, __VA_ARGS__) __VA_ARGS__ m(52)
#define XL_REP_53(m, ...)   XL_REP_52(m, __VA_ARGS__) __VA_ARGS__ m(53)
#define XL_REP_54(m, ...)   XL_REP_53(m, __VA_ARGS__) __VA_ARGS__ m(54)
#define XL_REP_55(m, ...)   XL_REP_54(m, __VA_ARGS__) __VA_ARGS__ m(55)
#define XL_REP_56(m, ...)   XL_REP_55(m, __VA_ARGS__) __VA_ARGS__ m(56)
#define XL_REP_57(m, ...)   XL_REP_56(m, __VA_ARGS__) __VA_ARGS__ m(57)
#define XL_REP_58(m, ...)   XL_REP_57(m, __VA_ARGS__) __VA_ARGS__ m(58)
#define XL_REP_59(m, ...)   XL_REP_58(m, __VA_ARGS__) __VA_ARGS__ m(59)
#define XL_REP_60(m, ...)   XL_REP_59(m, __VA_ARGS__) __VA_ARGS__ m(60)
#define XL_REP_61(m, ...)   XL_REP_60(m, __VA_ARGS__) __VA_ARGS__ m(61)
#define XL_REP_62(m, ...)   XL_REP_61(m, __VA_ARGS__) __VA_ARGS__ m(62)
#define XL_REP_63(m, ...)   XL_REP_62(m, __VA_ARGS__) __VA_ARGS__ m(63)
#define XL_REP_64(m, ...)   XL_REP_63(m, __VA_ARGS__) __VA_ARGS__ m(64)
#define XL_REP_65(m, ...)   XL_REP_64(m, __VA_ARGS__) __VA_ARGS__ m(65)
#define XL_REP_66(m, ...)   XL_REP_65(m, __VA_ARGS__) __VA_ARGS__ m(66)
#define XL_REP_67(m, ...)   XL_REP_66(m, __VA_ARGS__) __VA_ARGS__ m(67)
#define XL_REP_68(m, ...)   XL_REP_67(m, __VA_ARGS__) __VA_ARGS__ m(68)
#define XL_REP_69(m, ...)   XL_REP_68(m, __VA_ARGS__) __VA_ARGS__ m(69)
#define XL_REP_70(m, ...)   XL_REP_69(m, __VA_ARGS__) __VA_ARGS__ m(70)
#define XL_REP_71(m, ...)   XL_REP_70(m, __VA_ARGS__) __VA_ARGS__ m(71)
#define XL_REP_72(m, ...)   XL_REP_71(m, __VA_ARGS__) __VA_ARGS__ m(72)
#define XL_REP_73(m, ...)   XL_REP_72(m, __VA_ARGS__) __VA_ARGS__ m(73)
#define XL_REP_74(m, ...)   XL_REP_73(m, __VA_ARGS__) __VA_ARGS__ m(74)
#define XL_REP_75(m, ...)   XL_REP_74(m, __VA_ARGS__) __VA_ARGS__ m(75)
#define XL_REP_76(m, ...)   XL_REP_75(m, __VA_ARGS__) __VA_ARGS__ m(76)
#define XL_REP_77(m, ...)   XL_REP_76(m, __VA_ARGS__) __VA_ARGS__ m(77)
#define XL_REP_78(m, ...)   XL_REP_77(m, __VA_ARGS__) __VA_ARGS__ m(78)
#define XL_REP_79(m, ...)   XL_REP_78(m, __VA_ARGS__) __VA_ARGS__ m(79)
#define XL_REP_80(m, ...)   XL_REP_79(m, __VA_ARGS__) __VA_ARGS__ m(80)
#define XL_REP_81(m, ...)   XL_REP_80(m, __VA_ARGS__) __VA_ARGS__ m(81)
#define XL_REP_82(m, ...)   XL_REP_81(m, __VA_ARGS__) __VA_ARGS__ m(82)
#define XL_REP_83(m, ...)   XL_REP_82(m, __VA_ARGS__) __VA_ARGS__ m(83)
#define XL_REP_84(m, ...)   XL_REP_83(m, __VA_ARGS__) __VA_ARGS__ m(84)
#define XL_REP_85(m, ...)   XL_REP_84(m, __VA_ARGS__) __VA_ARGS__ m(85)
#define XL_REP_86(m, ...)   XL_REP_85(m, __VA_ARGS__) __VA_ARGS__ m(86)
#define XL_REP_87(m, ...)   XL_REP_86(m, __VA_ARGS__) __VA_ARGS__ m(87)
#define XL_REP_88(m, ...)   XL_REP_87(m, __VA_ARGS__) __VA_ARGS__ m(88)
#define XL_REP_89(m, ...)   XL_REP_88(m, __VA_ARGS__) __VA_ARGS__ m(89)
#define XL_REP_90(m, ...)   XL_REP_89(m, __VA_ARGS__) __VA_ARGS__ m(90)
#define XL_REP_91(m, ...)   XL_REP_90(m, __VA_ARGS__) __VA_ARGS__ m(91)
#define XL_REP_92(m, ...)   XL_REP_91(m, __VA_ARGS__) __VA_ARGS__ m(92)
#define XL_REP_93(m, ...)   XL_REP_92(m, __VA_ARGS__) __VA_ARGS__ m(93)
#define XL_REP_94(m, ...)   XL_REP_93(m, __VA_ARGS__) __VA_ARGS__ m(94)
#define XL_REP_95(m, ...)   XL_REP_94(m, __VA_ARGS__) __VA_ARGS__ m(95)
#define XL_REP_96(m, ...)   XL_REP_95(m, __VA_ARGS__) __VA_ARGS__ m(96)
#define XL_REP_97(m, ...)   XL_REP_96(m, __VA_ARGS__) __VA_ARGS__ m(97)
#define XL_REP_98(m, ...)   XL_REP_97(m, __VA_ARGS__) __VA_ARGS__ m(98)
#define XL_REP_99(m, ...)   XL_REP_98(m, __VA_ARGS__) __VA_ARGS__ m(99)

#define XL_REPX_0(m, ...)
#define XL_REPX_1(m, ...)   m(1)
#define XL_REPX_2(m, ...)   XL_REPX_1(m, __VA_ARGS__) __VA_ARGS__ m(2)
#define XL_REPX_3(m, ...)   XL_REPX_2(m, __VA_ARGS__) __VA_ARGS__ m(3)
#define XL_REPX_4(m, ...)   XL_REPX_3(m, __VA_ARGS__) __VA_ARGS__ m(4)
#define XL_REPX_5(m, ...)   XL_REPX_4(m, __VA_ARGS__) __VA_ARGS__ m(5)
#define XL_REPX_6(m, ...)   XL_REPX_5(m, __VA_ARGS__) __VA_ARGS__ m(6)
#define XL_REPX_7(m, ...)   XL_REPX_6(m, __VA_ARGS__) __VA_ARGS__ m(7)
#define XL_REPX_8(m, ...)   XL_REPX_7(m, __VA_ARGS__) __VA_ARGS__ m(8)
#define XL_REPX_9(m, ...)   XL_REPX_8(m, __VA_ARGS__) __VA_ARGS__ m(9)
#define XL_REPX_10(m, ...)  XL_REPX_9(m, __VA_ARGS__) __VA_ARGS__ m(10)
#define XL_REPX_11(m, ...)  XL_REPX_10(m, __VA_ARGS__) __VA_ARGS__ m(11)
#define XL_REPX_12(m, ...)  XL_REPX_11(m, __VA_ARGS__) __VA_ARGS__ m(12)
#define XL_REPX_13(m, ...)  XL_REPX_12(m, __VA_ARGS__) __VA_ARGS__ m(13)
#define XL_REPX_14(m, ...)  XL_REPX_13(m, __VA_ARGS__) __VA_ARGS__ m(14)
#define XL_REPX_15(m, ...)  XL_REPX_14(m, __VA_ARGS__) __VA_ARGS__ m(15)
#define XL_REPX_16(m, ...)  XL_REPX_15(m, __VA_ARGS__) __VA_ARGS__ m(16)
#define XL_REPX_17(m, ...)  XL_REPX_16(m, __VA_ARGS__) __VA_ARGS__ m(17)
#define XL_REPX_18(m, ...)  XL_REPX_17(m, __VA_ARGS__) __VA_ARGS__ m(18)
#define XL_REPX_19(m, ...)  XL_REPX_18(m, __VA_ARGS__) __VA_ARGS__ m(19)
#define XL_REPX_20(m, ...)  XL_REPX_19(m, __VA_ARGS__) __VA_ARGS__ m(20)
#define XL_REPX_21(m, ...)  XL_REPX_20(m, __VA_ARGS__) __VA_ARGS__ m(21)
#define XL_REPX_22(m, ...)  XL_REPX_21(m, __VA_ARGS__) __VA_ARGS__ m(22)
#define XL_REPX_23(m, ...)  XL_REPX_22(m, __VA_ARGS__) __VA_ARGS__ m(23)
#define XL_REPX_24(m, ...)  XL_REPX_23(m, __VA_ARGS__) __VA_ARGS__ m(24)
#define XL_REPX_25(m, ...)  XL_REPX_24(m, __VA_ARGS__) __VA_ARGS__ m(25)
#define XL_REPX_26(m, ...)  XL_REPX_25(m, __VA_ARGS__) __VA_ARGS__ m(26)
#define XL_REPX_27(m, ...)  XL_REPX_26(m, __VA_ARGS__) __VA_ARGS__ m(27)
#define XL_REPX_28(m, ...)  XL_REPX_27(m, __VA_ARGS__) __VA_ARGS__ m(28)
#define XL_REPX_29(m, ...)  XL_REPX_28(m, __VA_ARGS__) __VA_ARGS__ m(29)
#define XL_REPX_30(m, ...)  XL_REPX_29(m, __VA_ARGS__) __VA_ARGS__ m(30)
#define XL_REPX_31(m, ...)  XL_REPX_30(m, __VA_ARGS__) __VA_ARGS__ m(31)
#define XL_REPX_32(m, ...)  XL_REPX_31(m, __VA_ARGS__) __VA_ARGS__ m(32)
#define XL_REPX_33(m, ...)  XL_REPX_32(m, __VA_ARGS__) __VA_ARGS__ m(33)
#define XL_REPX_34(m, ...)  XL_REPX_33(m, __VA_ARGS__) __VA_ARGS__ m(34)
#define XL_REPX_35(m, ...)  XL_REPX_34(m, __VA_ARGS__) __VA_ARGS__ m(35)
#define XL_REPX_36(m, ...)  XL_REPX_35(m, __VA_ARGS__) __VA_ARGS__ m(36)
#define XL_REPX_37(m, ...)  XL_REPX_36(m, __VA_ARGS__) __VA_ARGS__ m(37)
#define XL_REPX_38(m, ...)  XL_REPX_37(m, __VA_ARGS__) __VA_ARGS__ m(38)
#define XL_REPX_39(m, ...)  XL_REPX_38(m, __VA_ARGS__) __VA_ARGS__ m(39)
#define XL_REPX_40(m, ...)  XL_REPX_39(m, __VA_ARGS__) __VA_ARGS__ m(40)
#define XL_REPX_41(m, ...)  XL_REPX_40(m, __VA_ARGS__) __VA_ARGS__ m(41)
#define XL_REPX_42(m, ...)  XL_REPX_41(m, __VA_ARGS__) __VA_ARGS__ m(42)
#define XL_REPX_43(m, ...)  XL_REPX_42(m, __VA_ARGS__) __VA_ARGS__ m(43)
#define XL_REPX_44(m, ...)  XL_REPX_43(m, __VA_ARGS__) __VA_ARGS__ m(44)
#define XL_REPX_45(m, ...)  XL_REPX_44(m, __VA_ARGS__) __VA_ARGS__ m(45)
#define XL_REPX_46(m, ...)  XL_REPX_45(m, __VA_ARGS__) __VA_ARGS__ m(46)
#define XL_REPX_47(m, ...)  XL_REPX_46(m, __VA_ARGS__) __VA_ARGS__ m(47)
#define XL_REPX_48(m, ...)  XL_REPX_47(m, __VA_ARGS__) __VA_ARGS__ m(48)
#define XL_REPX_49(m, ...)  XL_REPX_48(m, __VA_ARGS__) __VA_ARGS__ m(49)
#define XL_REPX_50(m, ...)  XL_REPX_49(m, __VA_ARGS__) __VA_ARGS__ m(50)
#define XL_REPX_51(m, ...)  XL_REPX_50(m, __VA_ARGS__) __VA_ARGS__ m(51)
#define XL_REPX_52(m, ...)  XL_REPX_51(m, __VA_ARGS__) __VA_ARGS__ m(52)
#define XL_REPX_53(m, ...)  XL_REPX_52(m, __VA_ARGS__) __VA_ARGS__ m(53)
#define XL_REPX_54(m, ...)  XL_REPX_53(m, __VA_ARGS__) __VA_ARGS__ m(54)
#define XL_REPX_55(m, ...)  XL_REPX_54(m, __VA_ARGS__) __VA_ARGS__ m(55)
#define XL_REPX_56(m, ...)  XL_REPX_55(m, __VA_ARGS__) __VA_ARGS__ m(56)
#define XL_REPX_57(m, ...)  XL_REPX_56(m, __VA_ARGS__) __VA_ARGS__ m(57)
#define XL_REPX_58(m, ...)  XL_REPX_57(m, __VA_ARGS__) __VA_ARGS__ m(58)
#define XL_REPX_59(m, ...)  XL_REPX_58(m, __VA_ARGS__) __VA_ARGS__ m(59)
#define XL_REPX_60(m, ...)  XL_REPX_59(m, __VA_ARGS__) __VA_ARGS__ m(60)
#define XL_REPX_61(m, ...)  XL_REPX_60(m, __VA_ARGS__) __VA_ARGS__ m(61)
#define XL_REPX_62(m, ...)  XL_REPX_61(m, __VA_ARGS__) __VA_ARGS__ m(62)
#define XL_REPX_63(m, ...)  XL_REPX_62(m, __VA_ARGS__) __VA_ARGS__ m(63)
#define XL_REPX_64(m, ...)  XL_REPX_63(m, __VA_ARGS__) __VA_ARGS__ m(64)
#define XL_REPX_65(m, ...)  XL_REPX_64(m, __VA_ARGS__) __VA_ARGS__ m(65)
#define XL_REPX_66(m, ...)  XL_REPX_65(m, __VA_ARGS__) __VA_ARGS__ m(66)
#define XL_REPX_67(m, ...)  XL_REPX_66(m, __VA_ARGS__) __VA_ARGS__ m(67)
#define XL_REPX_68(m, ...)  XL_REPX_67(m, __VA_ARGS__) __VA_ARGS__ m(68)
#define XL_REPX_69(m, ...)  XL_REPX_68(m, __VA_ARGS__) __VA_ARGS__ m(69)
#define XL_REPX_70(m, ...)  XL_REPX_69(m, __VA_ARGS__) __VA_ARGS__ m(70)
#define XL_REPX_71(m, ...)  XL_REPX_70(m, __VA_ARGS__) __VA_ARGS__ m(71)
#define XL_REPX_72(m, ...)  XL_REPX_71(m, __VA_ARGS__) __VA_ARGS__ m(72)
#define XL_REPX_73(m, ...)  XL_REPX_72(m, __VA_ARGS__) __VA_ARGS__ m(73)
#define XL_REPX_74(m, ...)  XL_REPX_73(m, __VA_ARGS__) __VA_ARGS__ m(74)
#define XL_REPX_75(m, ...)  XL_REPX_74(m, __VA_ARGS__) __VA_ARGS__ m(75)
#define XL_REPX_76(m, ...)  XL_REPX_75(m, __VA_ARGS__) __VA_ARGS__ m(76)
#define XL_REPX_77(m, ...)  XL_REPX_76(m, __VA_ARGS__) __VA_ARGS__ m(77)
#define XL_REPX_78(m, ...)  XL_REPX_77(m, __VA_ARGS__) __VA_ARGS__ m(78)
#define XL_REPX_79(m, ...)  XL_REPX_78(m, __VA_ARGS__) __VA_ARGS__ m(79)
#define XL_REPX_80(m, ...)  XL_REPX_79(m, __VA_ARGS__) __VA_ARGS__ m(80)
#define XL_REPX_81(m, ...)  XL_REPX_80(m, __VA_ARGS__) __VA_ARGS__ m(81)
#define XL_REPX_82(m, ...)  XL_REPX_81(m, __VA_ARGS__) __VA_ARGS__ m(82)
#define XL_REPX_83(m, ...)  XL_REPX_82(m, __VA_ARGS__) __VA_ARGS__ m(83)
#define XL_REPX_84(m, ...)  XL_REPX_83(m, __VA_ARGS__) __VA_ARGS__ m(84)
#define XL_REPX_85(m, ...)  XL_REPX_84(m, __VA_ARGS__) __VA_ARGS__ m(85)
#define XL_REPX_86(m, ...)  XL_REPX_85(m, __VA_ARGS__) __VA_ARGS__ m(86)
#define XL_REPX_87(m, ...)  XL_REPX_86(m, __VA_ARGS__) __VA_ARGS__ m(87)
#define XL_REPX_88(m, ...)  XL_REPX_87(m, __VA_ARGS__) __VA_ARGS__ m(88)
#define XL_REPX_89(m, ...)  XL_REPX_88(m, __VA_ARGS__) __VA_ARGS__ m(89)
#define XL_REPX_90(m, ...)  XL_REPX_89(m, __VA_ARGS__) __VA_ARGS__ m(90)
#define XL_REPX_91(m, ...)  XL_REPX_90(m, __VA_ARGS__) __VA_ARGS__ m(91)
#define XL_REPX_92(m, ...)  XL_REPX_91(m, __VA_ARGS__) __VA_ARGS__ m(92)
#define XL_REPX_93(m, ...)  XL_REPX_92(m, __VA_ARGS__) __VA_ARGS__ m(93)
#define XL_REPX_94(m, ...)  XL_REPX_93(m, __VA_ARGS__) __VA_ARGS__ m(94)
#define XL_REPX_95(m, ...)  XL_REPX_94(m, __VA_ARGS__) __VA_ARGS__ m(95)
#define XL_REPX_96(m, ...)  XL_REPX_95(m, __VA_ARGS__) __VA_ARGS__ m(96)
#define XL_REPX_97(m, ...)  XL_REPX_96(m, __VA_ARGS__) __VA_ARGS__ m(97)
#define XL_REPX_98(m, ...)  XL_REPX_97(m, __VA_ARGS__) __VA_ARGS__ m(98)
#define XL_REPX_99(m, ...)  XL_REPX_98(m, __VA_ARGS__) __VA_ARGS__ m(99)

#define XL_REPY_0(m, ...)
#define XL_REPY_1(m, ...)   m(1)
#define XL_REPY_2(m, ...)   XL_REPY_1(m, __VA_ARGS__) __VA_ARGS__ m(2)
#define XL_REPY_3(m, ...)   XL_REPY_2(m, __VA_ARGS__) __VA_ARGS__ m(3)
#define XL_REPY_4(m, ...)   XL_REPY_3(m, __VA_ARGS__) __VA_ARGS__ m(4)
#define XL_REPY_5(m, ...)   XL_REPY_4(m, __VA_ARGS__) __VA_ARGS__ m(5)
#define XL_REPY_6(m, ...)   XL_REPY_5(m, __VA_ARGS__) __VA_ARGS__ m(6)
#define XL_REPY_7(m, ...)   XL_REPY_6(m, __VA_ARGS__) __VA_ARGS__ m(7)
#define XL_REPY_8(m, ...)   XL_REPY_7(m, __VA_ARGS__) __VA_ARGS__ m(8)
#define XL_REPY_9(m, ...)   XL_REPY_8(m, __VA_ARGS__) __VA_ARGS__ m(9)
#define XL_REPY_10(m, ...)  XL_REPY_9(m, __VA_ARGS__) __VA_ARGS__ m(10)
#define XL_REPY_11(m, ...)  XL_REPY_10(m, __VA_ARGS__) __VA_ARGS__ m(11)
#define XL_REPY_12(m, ...)  XL_REPY_11(m, __VA_ARGS__) __VA_ARGS__ m(12)
#define XL_REPY_13(m, ...)  XL_REPY_12(m, __VA_ARGS__) __VA_ARGS__ m(13)
#define XL_REPY_14(m, ...)  XL_REPY_13(m, __VA_ARGS__) __VA_ARGS__ m(14)
#define XL_REPY_15(m, ...)  XL_REPY_14(m, __VA_ARGS__) __VA_ARGS__ m(15)
#define XL_REPY_16(m, ...)  XL_REPY_15(m, __VA_ARGS__) __VA_ARGS__ m(16)
#define XL_REPY_17(m, ...)  XL_REPY_16(m, __VA_ARGS__) __VA_ARGS__ m(17)
#define XL_REPY_18(m, ...)  XL_REPY_17(m, __VA_ARGS__) __VA_ARGS__ m(18)
#define XL_REPY_19(m, ...)  XL_REPY_18(m, __VA_ARGS__) __VA_ARGS__ m(19)
#define XL_REPY_20(m, ...)  XL_REPY_19(m, __VA_ARGS__) __VA_ARGS__ m(20)
#define XL_REPY_21(m, ...)  XL_REPY_20(m, __VA_ARGS__) __VA_ARGS__ m(21)
#define XL_REPY_22(m, ...)  XL_REPY_21(m, __VA_ARGS__) __VA_ARGS__ m(22)
#define XL_REPY_23(m, ...)  XL_REPY_22(m, __VA_ARGS__) __VA_ARGS__ m(23)
#define XL_REPY_24(m, ...)  XL_REPY_23(m, __VA_ARGS__) __VA_ARGS__ m(24)
#define XL_REPY_25(m, ...)  XL_REPY_24(m, __VA_ARGS__) __VA_ARGS__ m(25)
#define XL_REPY_26(m, ...)  XL_REPY_25(m, __VA_ARGS__) __VA_ARGS__ m(26)
#define XL_REPY_27(m, ...)  XL_REPY_26(m, __VA_ARGS__) __VA_ARGS__ m(27)
#define XL_REPY_28(m, ...)  XL_REPY_27(m, __VA_ARGS__) __VA_ARGS__ m(28)
#define XL_REPY_29(m, ...)  XL_REPY_28(m, __VA_ARGS__) __VA_ARGS__ m(29)
#define XL_REPY_30(m, ...)  XL_REPY_29(m, __VA_ARGS__) __VA_ARGS__ m(30)
#define XL_REPY_31(m, ...)  XL_REPY_30(m, __VA_ARGS__) __VA_ARGS__ m(31)
#define XL_REPY_32(m, ...)  XL_REPY_31(m, __VA_ARGS__) __VA_ARGS__ m(32)
#define XL_REPY_33(m, ...)  XL_REPY_32(m, __VA_ARGS__) __VA_ARGS__ m(33)
#define XL_REPY_34(m, ...)  XL_REPY_33(m, __VA_ARGS__) __VA_ARGS__ m(34)
#define XL_REPY_35(m, ...)  XL_REPY_34(m, __VA_ARGS__) __VA_ARGS__ m(35)
#define XL_REPY_36(m, ...)  XL_REPY_35(m, __VA_ARGS__) __VA_ARGS__ m(36)
#define XL_REPY_37(m, ...)  XL_REPY_36(m, __VA_ARGS__) __VA_ARGS__ m(37)
#define XL_REPY_38(m, ...)  XL_REPY_37(m, __VA_ARGS__) __VA_ARGS__ m(38)
#define XL_REPY_39(m, ...)  XL_REPY_38(m, __VA_ARGS__) __VA_ARGS__ m(39)
#define XL_REPY_40(m, ...)  XL_REPY_39(m, __VA_ARGS__) __VA_ARGS__ m(40)
#define XL_REPY_41(m, ...)  XL_REPY_40(m, __VA_ARGS__) __VA_ARGS__ m(41)
#define XL_REPY_42(m, ...)  XL_REPY_41(m, __VA_ARGS__) __VA_ARGS__ m(42)
#define XL_REPY_43(m, ...)  XL_REPY_42(m, __VA_ARGS__) __VA_ARGS__ m(43)
#define XL_REPY_44(m, ...)  XL_REPY_43(m, __VA_ARGS__) __VA_ARGS__ m(44)
#define XL_REPY_45(m, ...)  XL_REPY_44(m, __VA_ARGS__) __VA_ARGS__ m(45)
#define XL_REPY_46(m, ...)  XL_REPY_45(m, __VA_ARGS__) __VA_ARGS__ m(46)
#define XL_REPY_47(m, ...)  XL_REPY_46(m, __VA_ARGS__) __VA_ARGS__ m(47)
#define XL_REPY_48(m, ...)  XL_REPY_47(m, __VA_ARGS__) __VA_ARGS__ m(48)
#define XL_REPY_49(m, ...)  XL_REPY_48(m, __VA_ARGS__) __VA_ARGS__ m(49)
#define XL_REPY_50(m, ...)  XL_REPY_49(m, __VA_ARGS__) __VA_ARGS__ m(50)
#define XL_REPY_51(m, ...)  XL_REPY_50(m, __VA_ARGS__) __VA_ARGS__ m(51)
#define XL_REPY_52(m, ...)  XL_REPY_51(m, __VA_ARGS__) __VA_ARGS__ m(52)
#define XL_REPY_53(m, ...)  XL_REPY_52(m, __VA_ARGS__) __VA_ARGS__ m(53)
#define XL_REPY_54(m, ...)  XL_REPY_53(m, __VA_ARGS__) __VA_ARGS__ m(54)
#define XL_REPY_55(m, ...)  XL_REPY_54(m, __VA_ARGS__) __VA_ARGS__ m(55)
#define XL_REPY_56(m, ...)  XL_REPY_55(m, __VA_ARGS__) __VA_ARGS__ m(56)
#define XL_REPY_57(m, ...)  XL_REPY_56(m, __VA_ARGS__) __VA_ARGS__ m(57)
#define XL_REPY_58(m, ...)  XL_REPY_57(m, __VA_ARGS__) __VA_ARGS__ m(58)
#define XL_REPY_59(m, ...)  XL_REPY_58(m, __VA_ARGS__) __VA_ARGS__ m(59)
#define XL_REPY_60(m, ...)  XL_REPY_59(m, __VA_ARGS__) __VA_ARGS__ m(60)
#define XL_REPY_61(m, ...)  XL_REPY_60(m, __VA_ARGS__) __VA_ARGS__ m(61)
#define XL_REPY_62(m, ...)  XL_REPY_61(m, __VA_ARGS__) __VA_ARGS__ m(62)
#define XL_REPY_63(m, ...)  XL_REPY_62(m, __VA_ARGS__) __VA_ARGS__ m(63)
#define XL_REPY_64(m, ...)  XL_REPY_63(m, __VA_ARGS__) __VA_ARGS__ m(64)
#define XL_REPY_65(m, ...)  XL_REPY_64(m, __VA_ARGS__) __VA_ARGS__ m(65)
#define XL_REPY_66(m, ...)  XL_REPY_65(m, __VA_ARGS__) __VA_ARGS__ m(66)
#define XL_REPY_67(m, ...)  XL_REPY_66(m, __VA_ARGS__) __VA_ARGS__ m(67)
#define XL_REPY_68(m, ...)  XL_REPY_67(m, __VA_ARGS__) __VA_ARGS__ m(68)
#define XL_REPY_69(m, ...)  XL_REPY_68(m, __VA_ARGS__) __VA_ARGS__ m(69)
#define XL_REPY_70(m, ...)  XL_REPY_69(m, __VA_ARGS__) __VA_ARGS__ m(70)
#define XL_REPY_71(m, ...)  XL_REPY_70(m, __VA_ARGS__) __VA_ARGS__ m(71)
#define XL_REPY_72(m, ...)  XL_REPY_71(m, __VA_ARGS__) __VA_ARGS__ m(72)
#define XL_REPY_73(m, ...)  XL_REPY_72(m, __VA_ARGS__) __VA_ARGS__ m(73)
#define XL_REPY_74(m, ...)  XL_REPY_73(m, __VA_ARGS__) __VA_ARGS__ m(74)
#define XL_REPY_75(m, ...)  XL_REPY_74(m, __VA_ARGS__) __VA_ARGS__ m(75)
#define XL_REPY_76(m, ...)  XL_REPY_75(m, __VA_ARGS__) __VA_ARGS__ m(76)
#define XL_REPY_77(m, ...)  XL_REPY_76(m, __VA_ARGS__) __VA_ARGS__ m(77)
#define XL_REPY_78(m, ...)  XL_REPY_77(m, __VA_ARGS__) __VA_ARGS__ m(78)
#define XL_REPY_79(m, ...)  XL_REPY_78(m, __VA_ARGS__) __VA_ARGS__ m(79)
#define XL_REPY_80(m, ...)  XL_REPY_79(m, __VA_ARGS__) __VA_ARGS__ m(80)
#define XL_REPY_81(m, ...)  XL_REPY_80(m, __VA_ARGS__) __VA_ARGS__ m(81)
#define XL_REPY_82(m, ...)  XL_REPY_81(m, __VA_ARGS__) __VA_ARGS__ m(82)
#define XL_REPY_83(m, ...)  XL_REPY_82(m, __VA_ARGS__) __VA_ARGS__ m(83)
#define XL_REPY_84(m, ...)  XL_REPY_83(m, __VA_ARGS__) __VA_ARGS__ m(84)
#define XL_REPY_85(m, ...)  XL_REPY_84(m, __VA_ARGS__) __VA_ARGS__ m(85)
#define XL_REPY_86(m, ...)  XL_REPY_85(m, __VA_ARGS__) __VA_ARGS__ m(86)
#define XL_REPY_87(m, ...)  XL_REPY_86(m, __VA_ARGS__) __VA_ARGS__ m(87)
#define XL_REPY_88(m, ...)  XL_REPY_87(m, __VA_ARGS__) __VA_ARGS__ m(88)
#define XL_REPY_89(m, ...)  XL_REPY_88(m, __VA_ARGS__) __VA_ARGS__ m(89)
#define XL_REPY_90(m, ...)  XL_REPY_89(m, __VA_ARGS__) __VA_ARGS__ m(90)
#define XL_REPY_91(m, ...)  XL_REPY_90(m, __VA_ARGS__) __VA_ARGS__ m(91)
#define XL_REPY_92(m, ...)  XL_REPY_91(m, __VA_ARGS__) __VA_ARGS__ m(92)
#define XL_REPY_93(m, ...)  XL_REPY_92(m, __VA_ARGS__) __VA_ARGS__ m(93)
#define XL_REPY_94(m, ...)  XL_REPY_93(m, __VA_ARGS__) __VA_ARGS__ m(94)
#define XL_REPY_95(m, ...)  XL_REPY_94(m, __VA_ARGS__) __VA_ARGS__ m(95)
#define XL_REPY_96(m, ...)  XL_REPY_95(m, __VA_ARGS__) __VA_ARGS__ m(96)
#define XL_REPY_97(m, ...)  XL_REPY_96(m, __VA_ARGS__) __VA_ARGS__ m(97)
#define XL_REPY_98(m, ...)  XL_REPY_97(m, __VA_ARGS__) __VA_ARGS__ m(98)
#define XL_REPY_99(m, ...)  XL_REPY_98(m, __VA_ARGS__) __VA_ARGS__ m(99)

#define XL_REPZ_0(m, ...)
#define XL_REPZ_1(m, ...)   m(1)
#define XL_REPZ_2(m, ...)   XL_REPZ_1(m, __VA_ARGS__) __VA_ARGS__ m(2)
#define XL_REPZ_3(m, ...)   XL_REPZ_2(m, __VA_ARGS__) __VA_ARGS__ m(3)
#define XL_REPZ_4(m, ...)   XL_REPZ_3(m, __VA_ARGS__) __VA_ARGS__ m(4)
#define XL_REPZ_5(m, ...)   XL_REPZ_4(m, __VA_ARGS__) __VA_ARGS__ m(5)
#define XL_REPZ_6(m, ...)   XL_REPZ_5(m, __VA_ARGS__) __VA_ARGS__ m(6)
#define XL_REPZ_7(m, ...)   XL_REPZ_6(m, __VA_ARGS__) __VA_ARGS__ m(7)
#define XL_REPZ_8(m, ...)   XL_REPZ_7(m, __VA_ARGS__) __VA_ARGS__ m(8)
#define XL_REPZ_9(m, ...)   XL_REPZ_8(m, __VA_ARGS__) __VA_ARGS__ m(9)
#define XL_REPZ_10(m, ...)  XL_REPZ_9(m, __VA_ARGS__) __VA_ARGS__ m(10)
#define XL_REPZ_11(m, ...)  XL_REPZ_10(m, __VA_ARGS__) __VA_ARGS__ m(11)
#define XL_REPZ_12(m, ...)  XL_REPZ_11(m, __VA_ARGS__) __VA_ARGS__ m(12)
#define XL_REPZ_13(m, ...)  XL_REPZ_12(m, __VA_ARGS__) __VA_ARGS__ m(13)
#define XL_REPZ_14(m, ...)  XL_REPZ_13(m, __VA_ARGS__) __VA_ARGS__ m(14)
#define XL_REPZ_15(m, ...)  XL_REPZ_14(m, __VA_ARGS__) __VA_ARGS__ m(15)
#define XL_REPZ_16(m, ...)  XL_REPZ_15(m, __VA_ARGS__) __VA_ARGS__ m(16)
#define XL_REPZ_17(m, ...)  XL_REPZ_16(m, __VA_ARGS__) __VA_ARGS__ m(17)
#define XL_REPZ_18(m, ...)  XL_REPZ_17(m, __VA_ARGS__) __VA_ARGS__ m(18)
#define XL_REPZ_19(m, ...)  XL_REPZ_18(m, __VA_ARGS__) __VA_ARGS__ m(19)
#define XL_REPZ_20(m, ...)  XL_REPZ_19(m, __VA_ARGS__) __VA_ARGS__ m(20)
#define XL_REPZ_21(m, ...)  XL_REPZ_20(m, __VA_ARGS__) __VA_ARGS__ m(21)
#define XL_REPZ_22(m, ...)  XL_REPZ_21(m, __VA_ARGS__) __VA_ARGS__ m(22)
#define XL_REPZ_23(m, ...)  XL_REPZ_22(m, __VA_ARGS__) __VA_ARGS__ m(23)
#define XL_REPZ_24(m, ...)  XL_REPZ_23(m, __VA_ARGS__) __VA_ARGS__ m(24)
#define XL_REPZ_25(m, ...)  XL_REPZ_24(m, __VA_ARGS__) __VA_ARGS__ m(25)
#define XL_REPZ_26(m, ...)  XL_REPZ_25(m, __VA_ARGS__) __VA_ARGS__ m(26)
#define XL_REPZ_27(m, ...)  XL_REPZ_26(m, __VA_ARGS__) __VA_ARGS__ m(27)
#define XL_REPZ_28(m, ...)  XL_REPZ_27(m, __VA_ARGS__) __VA_ARGS__ m(28)
#define XL_REPZ_29(m, ...)  XL_REPZ_28(m, __VA_ARGS__) __VA_ARGS__ m(29)
#define XL_REPZ_30(m, ...)  XL_REPZ_29(m, __VA_ARGS__) __VA_ARGS__ m(30)
#define XL_REPZ_31(m, ...)  XL_REPZ_30(m, __VA_ARGS__) __VA_ARGS__ m(31)
#define XL_REPZ_32(m, ...)  XL_REPZ_31(m, __VA_ARGS__) __VA_ARGS__ m(32)
#define XL_REPZ_33(m, ...)  XL_REPZ_32(m, __VA_ARGS__) __VA_ARGS__ m(33)
#define XL_REPZ_34(m, ...)  XL_REPZ_33(m, __VA_ARGS__) __VA_ARGS__ m(34)
#define XL_REPZ_35(m, ...)  XL_REPZ_34(m, __VA_ARGS__) __VA_ARGS__ m(35)
#define XL_REPZ_36(m, ...)  XL_REPZ_35(m, __VA_ARGS__) __VA_ARGS__ m(36)
#define XL_REPZ_37(m, ...)  XL_REPZ_36(m, __VA_ARGS__) __VA_ARGS__ m(37)
#define XL_REPZ_38(m, ...)  XL_REPZ_37(m, __VA_ARGS__) __VA_ARGS__ m(38)
#define XL_REPZ_39(m, ...)  XL_REPZ_38(m, __VA_ARGS__) __VA_ARGS__ m(39)
#define XL_REPZ_40(m, ...)  XL_REPZ_39(m, __VA_ARGS__) __VA_ARGS__ m(40)
#define XL_REPZ_41(m, ...)  XL_REPZ_40(m, __VA_ARGS__) __VA_ARGS__ m(41)
#define XL_REPZ_42(m, ...)  XL_REPZ_41(m, __VA_ARGS__) __VA_ARGS__ m(42)
#define XL_REPZ_43(m, ...)  XL_REPZ_42(m, __VA_ARGS__) __VA_ARGS__ m(43)
#define XL_REPZ_44(m, ...)  XL_REPZ_43(m, __VA_ARGS__) __VA_ARGS__ m(44)
#define XL_REPZ_45(m, ...)  XL_REPZ_44(m, __VA_ARGS__) __VA_ARGS__ m(45)
#define XL_REPZ_46(m, ...)  XL_REPZ_45(m, __VA_ARGS__) __VA_ARGS__ m(46)
#define XL_REPZ_47(m, ...)  XL_REPZ_46(m, __VA_ARGS__) __VA_ARGS__ m(47)
#define XL_REPZ_48(m, ...)  XL_REPZ_47(m, __VA_ARGS__) __VA_ARGS__ m(48)
#define XL_REPZ_49(m, ...)  XL_REPZ_48(m, __VA_ARGS__) __VA_ARGS__ m(49)
#define XL_REPZ_50(m, ...)  XL_REPZ_49(m, __VA_ARGS__) __VA_ARGS__ m(50)
#define XL_REPZ_51(m, ...)  XL_REPZ_50(m, __VA_ARGS__) __VA_ARGS__ m(51)
#define XL_REPZ_52(m, ...)  XL_REPZ_51(m, __VA_ARGS__) __VA_ARGS__ m(52)
#define XL_REPZ_53(m, ...)  XL_REPZ_52(m, __VA_ARGS__) __VA_ARGS__ m(53)
#define XL_REPZ_54(m, ...)  XL_REPZ_53(m, __VA_ARGS__) __VA_ARGS__ m(54)
#define XL_REPZ_55(m, ...)  XL_REPZ_54(m, __VA_ARGS__) __VA_ARGS__ m(55)
#define XL_REPZ_56(m, ...)  XL_REPZ_55(m, __VA_ARGS__) __VA_ARGS__ m(56)
#define XL_REPZ_57(m, ...)  XL_REPZ_56(m, __VA_ARGS__) __VA_ARGS__ m(57)
#define XL_REPZ_58(m, ...)  XL_REPZ_57(m, __VA_ARGS__) __VA_ARGS__ m(58)
#define XL_REPZ_59(m, ...)  XL_REPZ_58(m, __VA_ARGS__) __VA_ARGS__ m(59)
#define XL_REPZ_60(m, ...)  XL_REPZ_59(m, __VA_ARGS__) __VA_ARGS__ m(60)
#define XL_REPZ_61(m, ...)  XL_REPZ_60(m, __VA_ARGS__) __VA_ARGS__ m(61)
#define XL_REPZ_62(m, ...)  XL_REPZ_61(m, __VA_ARGS__) __VA_ARGS__ m(62)
#define XL_REPZ_63(m, ...)  XL_REPZ_62(m, __VA_ARGS__) __VA_ARGS__ m(63)
#define XL_REPZ_64(m, ...)  XL_REPZ_63(m, __VA_ARGS__) __VA_ARGS__ m(64)
#define XL_REPZ_65(m, ...)  XL_REPZ_64(m, __VA_ARGS__) __VA_ARGS__ m(65)
#define XL_REPZ_66(m, ...)  XL_REPZ_65(m, __VA_ARGS__) __VA_ARGS__ m(66)
#define XL_REPZ_67(m, ...)  XL_REPZ_66(m, __VA_ARGS__) __VA_ARGS__ m(67)
#define XL_REPZ_68(m, ...)  XL_REPZ_67(m, __VA_ARGS__) __VA_ARGS__ m(68)
#define XL_REPZ_69(m, ...)  XL_REPZ_68(m, __VA_ARGS__) __VA_ARGS__ m(69)
#define XL_REPZ_70(m, ...)  XL_REPZ_69(m, __VA_ARGS__) __VA_ARGS__ m(70)
#define XL_REPZ_71(m, ...)  XL_REPZ_70(m, __VA_ARGS__) __VA_ARGS__ m(71)
#define XL_REPZ_72(m, ...)  XL_REPZ_71(m, __VA_ARGS__) __VA_ARGS__ m(72)
#define XL_REPZ_73(m, ...)  XL_REPZ_72(m, __VA_ARGS__) __VA_ARGS__ m(73)
#define XL_REPZ_74(m, ...)  XL_REPZ_73(m, __VA_ARGS__) __VA_ARGS__ m(74)
#define XL_REPZ_75(m, ...)  XL_REPZ_74(m, __VA_ARGS__) __VA_ARGS__ m(75)
#define XL_REPZ_76(m, ...)  XL_REPZ_75(m, __VA_ARGS__) __VA_ARGS__ m(76)
#define XL_REPZ_77(m, ...)  XL_REPZ_76(m, __VA_ARGS__) __VA_ARGS__ m(77)
#define XL_REPZ_78(m, ...)  XL_REPZ_77(m, __VA_ARGS__) __VA_ARGS__ m(78)
#define XL_REPZ_79(m, ...)  XL_REPZ_78(m, __VA_ARGS__) __VA_ARGS__ m(79)
#define XL_REPZ_80(m, ...)  XL_REPZ_79(m, __VA_ARGS__) __VA_ARGS__ m(80)
#define XL_REPZ_81(m, ...)  XL_REPZ_80(m, __VA_ARGS__) __VA_ARGS__ m(81)
#define XL_REPZ_82(m, ...)  XL_REPZ_81(m, __VA_ARGS__) __VA_ARGS__ m(82)
#define XL_REPZ_83(m, ...)  XL_REPZ_82(m, __VA_ARGS__) __VA_ARGS__ m(83)
#define XL_REPZ_84(m, ...)  XL_REPZ_83(m, __VA_ARGS__) __VA_ARGS__ m(84)
#define XL_REPZ_85(m, ...)  XL_REPZ_84(m, __VA_ARGS__) __VA_ARGS__ m(85)
#define XL_REPZ_86(m, ...)  XL_REPZ_85(m, __VA_ARGS__) __VA_ARGS__ m(86)
#define XL_REPZ_87(m, ...)  XL_REPZ_86(m, __VA_ARGS__) __VA_ARGS__ m(87)
#define XL_REPZ_88(m, ...)  XL_REPZ_87(m, __VA_ARGS__) __VA_ARGS__ m(88)
#define XL_REPZ_89(m, ...)  XL_REPZ_88(m, __VA_ARGS__) __VA_ARGS__ m(89)
#define XL_REPZ_90(m, ...)  XL_REPZ_89(m, __VA_ARGS__) __VA_ARGS__ m(90)
#define XL_REPZ_91(m, ...)  XL_REPZ_90(m, __VA_ARGS__) __VA_ARGS__ m(91)
#define XL_REPZ_92(m, ...)  XL_REPZ_91(m, __VA_ARGS__) __VA_ARGS__ m(92)
#define XL_REPZ_93(m, ...)  XL_REPZ_92(m, __VA_ARGS__) __VA_ARGS__ m(93)
#define XL_REPZ_94(m, ...)  XL_REPZ_93(m, __VA_ARGS__) __VA_ARGS__ m(94)
#define XL_REPZ_95(m, ...)  XL_REPZ_94(m, __VA_ARGS__) __VA_ARGS__ m(95)
#define XL_REPZ_96(m, ...)  XL_REPZ_95(m, __VA_ARGS__) __VA_ARGS__ m(96)
#define XL_REPZ_97(m, ...)  XL_REPZ_96(m, __VA_ARGS__) __VA_ARGS__ m(97)
#define XL_REPZ_98(m, ...)  XL_REPZ_97(m, __VA_ARGS__) __VA_ARGS__ m(98)
#define XL_REPZ_99(m, ...)  XL_REPZ_98(m, __VA_ARGS__) __VA_ARGS__ m(99)

// Extends to
// m(0) d m(1) d ... d m(n)
#define XL_REP_MAX          99
#define XL_REP(m, n, d)     XL_CONN(XL_REP_, n)(m, d)
#define XL_REPX(m, n, ...)  XL_CONN(XL_REPX_, n)(m, __VA_ARGS__)
#define XL_REPY(m, n, ...)  XL_CONN(XL_REPY_, n)(m, __VA_ARGS__)
#define XL_REPZ(m, n, ...)  XL_CONN(XL_REPZ_, n)(m, __VA_ARGS__)

} // namespace xl

#endif // #ifndef __XLMACROS_H_83436072_95E5_4500_A129_49EBFD0899E5_INCLUDED__
