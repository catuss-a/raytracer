/* BRILANTE Jason "Damdoshi"
** Pentacle Technologie 2010
**
** Lib dgeneric
** Utils which check system call and
** which report memory leak
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

#ifndef			__DGENERIC_H__
# define		__DGENERIC_H__

/* Dependencies
*/
# include		<stdarg.h>
# include		<stdlib.h>

/* Define for XMAP declaration and XMAP erase
** Use the first at the end of your main variable
** declaration
** Use the second each time you have an opportunity
** to leave your program
*/
# define		DECLARE_XMAP			t_ram *ram; ram = xdeclare()
# define		KILL_XMAP(a)			xfreedom((void*)(a), USE_XMAP)

/* Data format for pointer used -- Don't use it yourself
*/
typedef struct		s_ram
{
  void			*memory;
  const char		*name;
  unsigned char		usage;
  struct s_ram		*next;
}			t_ram;

t_ram			*xdeclare(void);

/* Allocate and free memory.
** Usage are: INIT (Don't use it), TEMPORARY(x) where
** x is used for free only some temporary allocation
** xftmp (Free temporary) free memory alloc with TEMPORARY(x)
** PERMENENT alloc permenently
** xfreedom free all memory and detroy the XMAP -- Don't use it
** xmemset put all bytes in a memory entity to a sent data
*/
# define		INIT				0
# define		PERMENENT			1
# define		XUSE				PERMENENT /* This one is better for free */
# define		PERMANENT			PERMENENT /* Often made mistake */
# define		USE_XMAP			PERMANENT /* Retro-compatibility */
/* Reserved: 0-9 ; Max is 125 */
# define		TEMPORARY(x)			((x) >= 0) ? (((x) + 2)) : ((-1))
void			*xmalloc(unsigned int		size_of,
				 const char		*name,
				 const char		action);
void			xfree(void			*ptr,
			      char			action);
void			xftmp(void			*ram,
			      char			action);
void			xfreedom(void			*ram,
				 char			action);
void			xmemset(void			*ptr,
				unsigned int		size_oflen,
				char			value);

/* File, and output management
 */
# define		STD_IN				0
# define		STD_OUT				1
# define		STD_ERR				2
int			xopen(const char		*path,
			      int			flags,
			      ...);
void			xclose(int			fd);
int			file_exist(const char		*path);
int			file_read(const char		*path);
int			file_write(const char		*path);
int			file_exec(const char		*path);

int			xwrite(int			output,
			       const void		*ptr,
			       unsigned int		size);
int			xread(int			input,
			      void			*ptr,
			      unsigned int		size);

/* Proccessus stuff
** xexec take a path or filename for its first entry
*/
# define		SON				0
int			xfork(void);
int			xwait(int			*status);
int			xexec(char			*str,
			      char			**argv,
			      char			**env);
int			xpipe(int			fd[2]);

/* Utils
*/
# define		UNUSED				__attribute__((unused))
void			*liveliness(void		*ptr,
				    unsigned char	usage);

/* Debugging Tools
** Functions which are enabled only if 
** __GENERAL_DEBUG__ is defined in the Makefile
**
** debug display a message if the macro is define
** err_msg display a message a complete erro message
** and exit if the macro is define, else it display
** an error number and exit
*/
void			debug(const int			code,
			      const char		*str1,
			      const char		*str2);
void			err_msg(const char		*errcode,
				unsigned int		object,
				const char		*sentence);
void			showmem(char			action,
				void			*ptr);

/* Generic functions
*/
void			dswap(unsigned int		*a,
			      unsigned int		*b);

/* Error messages
*/

# define		XMALLOC_NUMBER			"Error 0a: "
# define		XMALLOC_ERROR			" Memory allocation failed."
# define		XMALLOCB_NUMBER			"Error 0b: "
# define		XMALLOCB_ERROR			" XMap system allocation failed."
# define		XFREE_NUMBER			"Error 1a: "
# define		XFREE_ERROR			" Memory free failed."
# define		XFORK_NUMBER			"Error 2: "
# define		XFORK_ERROR			" Can't fork."
# define		XWAIT_NUMBER			"Error 3: "
# define		XWAIT_ERROR			" Wait failed."
# define		XWRITE_NUMBER			"Error 4: "
# define		XWRITE_ERROR			" Can't write."
# define		XREAD_NUMBER		       	"Error 5: "
# define		XREAD_ERROR			" Can't read."
# define		XCLOSE_NUMBER			"Error 6a: "
# define		XCLOSE_ERROR			" Can't close this file descriptor."
# define		XCLOSE_STDNUM			"Error 6b: "
# define		XCLOSE_STDERR			" Trying to close STD_IN, STD_OUT or STD_ERR."
# define		XEXEC_DENIED			" Permission denied."
# define		XEXEC_CANTFIND			" Target file does not exist."
# define		XPIPE_NUMBER			"Error 7: "
# define		XPIPE_ERROR			" Can't pipe him."

# define		XOPEN_DENIED			":Permission denied."

#endif	/*		__DGENERIC_H__	*/
