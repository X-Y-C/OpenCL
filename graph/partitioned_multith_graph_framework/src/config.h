#ifndef __CONFIG_H__
#define __CONFIG_H__

#include <climits>

#define BFS
#define PROP_TYPE int
#define MAX_PROP (INT_MAX - 1)
#define BLK_SIZE (128*1024)
#define kDamp 0.85


#ifdef BFS
inline PROP_TYPE compute(PROP_TYPE uProp, PROP_TYPE eProp, PROP_TYPE vProp){
	PROP_TYPE tmp = uProp + eProp;
	if(tmp < vProp) return tmp;
	else return vProp;
}

inline bool updateCondition(PROP_TYPE vProp, PROP_TYPE tProp){
	return (vProp > tProp);
}

#elif PR
inline PROP_TYPE compute(PROP_TYPE uProp, PROP_TYPE eProp, PROP_TYPE vProp){
	return (0.85*uProp + vProp);
}
inline bool updateCondition(PROP_TYPE vProp, PROP_TYPE tProp){
	return (abs(vProp - tProp) > 0.001);
}


#elif SSSP
inline PROP_TYPE compute(PROP_TYPE uProp, PROP_TYPE eProp, PROP_TYPE vProp){
	PROP_TYPE tmp = uProp + eProp;
	if(tmp < vProp) return tmp;
	else return vProp;
}

inline bool updateCondition(PROP_TYPE vProp, PROP_TYPE tProp){
	return (vProp > tProp);
}

#endif

#endif

