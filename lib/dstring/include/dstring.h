/* BRILLANTE Jason "Damdoshi"
** Pentacle Technologie 2010
**
** Lib DString
** Easy manipulation of string
*/

#ifndef		__DSTRING_H__
# define	__DSTRING_H__

/* Dependencies
** Need DGeneric Library!
*/
#include	<stdarg.h>

/* Return the size of the sent string
*/
int		dstrlen(const char	*str);
int		dstrlenc(const char	*str,
			 const char	*symbols);

/* Return the difference between the two non equal,
** or the two last character
** (Return 0 if equal)
*/
int		dstrcmp(const char	*str1,
			const char	*str2);

/* Return the index of the first c occurence
** else return -1
*/
int		dstrfind(const char	*str,
			 char		c);

/* Concat two string
*/
char		*dstrcat(const char	*str1,
			 const char	*str2);

/* Shift from right to left and full with eos char
*/
char		*dstrleft(char		*str,
			  int		shift,
			  char		eos);

/* Change case of a sent string
*/
char		*dstrupper(char		*str);
char		*dstrlower(char		*str);
char		*dstrinvcase(char	*str);

/* Transform an int into a string
*/
# define	BINARY			"01"
# define	QUARTET			"0123"
# define	OCTAL			"01234567"
# define	DECIMAL			"0123456789"
# define	HEXADECIMAL		"0123456789ABCDEF"
# define	HEXADECIMAL_MAJ		HEXADECIMAL
# define	HEXADECIMAL_MIN		"0123456789abcdef"
# define	ALPHABETIC		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
# define	ALPHABETIC_MAJ		ALPHABETIC
# define	ALPHABETIC_MIN		"abcdefghijklmnopqrstuvwxyz"
# define	SIGN_POSITIVE		1
# define        SIGN_ORIGINAL		0
# define	SIGN_NEGATIVE		(-1)

char		*ditoa(const int	code,
		       const char	*base,
		       const int	sign);
int		datoi(const char	*str);

/* Display strings on screen. Return the number of byte wrote.
*/
int		dputs(unsigned int	nb_str,
		      ...);

/* Duplicate a string
*/
# define	DUP_ALL			-1
char		*dstrdup(const char	*str,
			 int		len);
# define	dstrndup		dstrdup

/* About wordtab
*/
char		**dwtab(const char	*str,
			const char	*symbols);
int		dwtablen(char		**wt);
void		dwtabputs(char		**str);

#endif	/*	__DSTRING_H__	*/
