
#ifndef BIT_MATH_H
#define	BIT_MATH_H

#define SETBIT(REG,BIT)  (REG |= 1 << BIT)
#define CLRBIT(REG,BIT)  (REG &= ~(1 << BIT))
#define TOGBIT(REG,BIT)  (REG ^= 1 << BIT)
#define READBIT(REG,BIT) ((REG >> BIT) & 1)

#endif	/* BIT_MATH_H */
