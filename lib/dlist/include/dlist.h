/* BRILANTE Jason "Damdoshi"
** Pentacle Technologie 2010
**
** Lib dlist
** Double and circular chained list
** with a sentinel
**
** Please report all bugs at:
** damdoshi@pentacle-technologie.net
*/

/* Copyright (c) 2010, BRILLANTE Jason "Damdoshi"
** All rights reserved.
**
** Redistribution and use in source and binary forms, with or without modification,
** are permitted provided that the following conditions are met:
**
** * Redistributions of source code must retain the above copyright notice,
** this list of conditions and the following disclaimer.
** * Redistributions in binary form must reproduce the above copyright notice,
** this list of conditions and the following disclaimer in the documentation
** and/or other materials provided with the distribution.
** * Neither the name of Pentacle Technologie (Association Loi 1901) nor
** the names of its contributors may be used to endorse or promote products derived
** from this software without specific prior written permission.
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
** AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
** IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
** ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
** LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
** CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
** SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
** INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
** CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
** ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
** POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef			__DLIST_H__
# define		__DLIST_H__

/* Dependencies
*/
# include		<stdarg.h>

/* Utilities
*/
# define		INT(x)				((int)(x))
# define		FLOAT(x)			((float)(x))
# define		CHAR(x)				((char)(x))
# define		STRING(x)			((char*)(x))
# define		WORDTAB(x)			((char**)(x))
# define		RSIZE_OF(snt)			((unsigned int)((snt)->data))
# define		WSIZE_OF(snt, size)		((snt)->data = (unsigned int)(size))
# define		NEXT(x)				(x) = (x)->next
# define		PREV(x)				(x) = (x)->prev

/* Start and End are the beginning and the end of a list
** when the t_list structure is a sentinel
**
** The data part of the sentinel is already allocated with 
** the size of element in memory
** This element is never used by function. It leave you
** the possibility of using an other size_of.
** If you wish to use it, try the SIZE_OF macro
*/
# define		first				next
# define		last				prev
# define		dsize_of			data
typedef struct		s_list
{
  void			*data;
  struct s_list		*next;
  struct s_list		*prev;
}			t_list;

typedef struct s_list	t_snt;
typedef struct s_list	t_lst;
typedef void		size_of;

/* Generate a list with one empty element (data = NULL), return a pointer on sentinel
** dllg as DList List Generate
*/
t_snt			*dllg(void);
# define		dl_generate			dllg

/* Generate a 'list-array' with a size equivalent to the sent value
** This operation is equal to array = malloc(sizeof(*length));
** It malloc the data in the list two thanks to the second argument
** dlma as DList Malloc Array
*/
# define		DL_NMALLOC			0
t_snt			*dlma(unsigned int		length,
			      unsigned int		sdata);
# define		dl_malloc			dlma

/* Return a value (A pointer to a copy) or an adresse found 
** in list which is a LST. Loop on overflow.
** dlcv as DList Catch Value
** dlca as DList Catch Address
*/
void			*dlcv(const t_snt		*snt,
			      int			index,
			      unsigned int		size_of);
void			*dlca(const t_snt		*snt,
			      int			index);
# define		dl_catchval			dlcv
# define		dl_catchadr			dlca

/* Assign a value (A pointer to a copy) or and adresse found 
** in a list. Loop on onverflow.
** dlav as DList Assign Value
** dlaa as DList Assign Address
*/
void			dlav(const t_snt		*snt,
			     int			index,
			     const void			*value,
			     unsigned int		size_of);
void			dlaa(const t_snt		*snt,
			     int			index,
			     void			*address);
# define		dl_assignval			dlav
# define		dl_assignadr			dlaa

/* Swap all next and previous elements of the sent list
*/
void			dlrev(t_snt			*snt);
# define		dl_reverse			dlrev

/* Delete the element which is at index
** Element is not only erased, the list is cut too
*/
void			dldel(t_snt			*snt,
			      int			index);
# define		dl_delete			dldel

/* Shift the middle of the sent list in a direction or in an other
*/
void			dlsri(t_snt			*snt);
void			dlsle(t_snt			*snt);
# define		dl_shift_right			dlsri
# define	        dl_shift_left			dlsle

/* Insert and element at the sent index. Next element are pushed
** to the next index
** dlpvi as DList Push Value In
** dlpai as DList Push Address In
*/
void			dlpvi(const t_snt		*snt,
			      int			index,
			      void			*value,
			      unsigned int		size_of);
void			dlpai(const t_snt		*snt,
			      int			index,
			      void			*address);
# define		dl_pushval_in			dlvpi
# define		dl_pushadr_in			dlpai

/* Insert an element, value or address, at the beginning, or ending 
** of the list
** dlpvb as DList Put Value at Beginning
** dlpab as DList Put Address at Beginning
** dlpve as DList Put Value at Ending
** dlpae as DList Put Address at Ending
** 
*/
t_lst			*dlpvb(t_snt			*snt,
			      const void		*value,
			      unsigned int		size_of);
t_lst			*dlpab(t_snt			*snt,
			      void			*address);
t_lst			*dlpve(t_snt			*snt,
			       const void		*value,
			       unsigned int		size_of);
t_lst			*dlpae(t_snt			*snt,
			       void			*value);
# define		dl_putval_begin			dlpvb
# define		dl_putadr_begin			dlpab
# define		dl_putval_end			dlpve
# define		dl_putadr_end			dlpae

/* Find a value in the list, return the index
 */
int			dlfind(const t_snt		*snt,
			       const void		*value,
			       unsigned int		size_of);
# define		dl_find				dlfind

/* Return the length of the sent list
*/
int			dllen(const t_snt		*snt);
# define		dl_len				dllen

/* Return a wordtab built with string in list
** Return a list built thanks to a wordtab
*/
char			**dlwordtab(const t_snt		*snt);
t_lst			*dlwtlist(const char		**wt);
# define		dl_list_to_wordtab		dlwordtab
# define		dl_wordtab_to_list		dlwtlist

/* Duplicate a list
*/
t_snt			*dldup(t_snt			*snt,
			       unsigned int		size_of);
# define		dl_dup				dldup

/* Concatenate two list in a new list
*/
t_snt			*dlcat(t_snt			*snt,
			       int			nbr,
			      ...);
# define		dl_concat			dlcat

/* Destroy a list
*/
void			dlfree(t_snt			*snt);
# define		dl_free				dlfree

/* About strings
*/
int			dlprint(const t_snt		*snt);
int			dlstrlen(const t_snt		*snt);
char			*dlstrcat(const t_snt		*snt);


/* Utilities
*/
void			dldebug(const char		*str);
void			dlswap_void(void		**elem1,
				    void		**elem2);
void			dlerase(t_snt			*snt);
void			*dldup_binary(const void	*data,
				      unsigned int	size_of);
int			dlcmp_binary(const void		*data1,
				     const void		*data2,
				     unsigned int	size_of);
int			dlcheck_list(t_snt		*snt);
void			dlshow(t_snt			*snt);
# define		dl_swap_void			dlswap_void
# define		dl_all_to_zero			dlerase
# define		dl_binary_dup			dldup_binary
# define		dl_binary_cmp			dlcmp_binary
# define		dl_checklist			dlcheck_list
# define		dl_show				dlshow
# define		dl_showlist			dlshow

#endif	/*		__DLIST_H__	*/
