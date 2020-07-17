/*
 * SPDX-License-Identifier: BSD-2-Clause
 *
 * Copyright (C) 2018 embedded brains GmbH
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include <rtems/test.h>

#include <errno.h>

#define T_STRERROR_CASE(eno) case eno: return #eno

const char *T_strerror(int eno)
{
	switch (eno) {
	case 0:
		return "0";
	T_STRERROR_CASE(E2BIG);
	T_STRERROR_CASE(EACCES);
	T_STRERROR_CASE(EADDRINUSE);
	T_STRERROR_CASE(EADDRNOTAVAIL);
	T_STRERROR_CASE(EAFNOSUPPORT);
	T_STRERROR_CASE(EAGAIN);
	T_STRERROR_CASE(EALREADY);
	T_STRERROR_CASE(EBADF);
	T_STRERROR_CASE(EBADMSG);
	T_STRERROR_CASE(EBUSY);
	T_STRERROR_CASE(ECANCELED);
	T_STRERROR_CASE(ECHILD);
	T_STRERROR_CASE(ECONNABORTED);
	T_STRERROR_CASE(ECONNREFUSED);
	T_STRERROR_CASE(ECONNRESET);
	T_STRERROR_CASE(EDEADLK);
	T_STRERROR_CASE(EDESTADDRREQ);
	T_STRERROR_CASE(EDOM);
	T_STRERROR_CASE(EDQUOT);
	T_STRERROR_CASE(EEXIST);
	T_STRERROR_CASE(EFAULT);
	T_STRERROR_CASE(EFBIG);
	T_STRERROR_CASE(EHOSTDOWN);
	T_STRERROR_CASE(EHOSTUNREACH);
	T_STRERROR_CASE(EIDRM);
	T_STRERROR_CASE(EILSEQ);
	T_STRERROR_CASE(EINPROGRESS);
	T_STRERROR_CASE(EINTR);
	T_STRERROR_CASE(EINVAL);
	T_STRERROR_CASE(EIO);
	T_STRERROR_CASE(EISCONN);
	T_STRERROR_CASE(EISDIR);
	T_STRERROR_CASE(ELOOP);
	T_STRERROR_CASE(EMFILE);
	T_STRERROR_CASE(EMLINK);
	T_STRERROR_CASE(EMSGSIZE);
	T_STRERROR_CASE(EMULTIHOP);
	T_STRERROR_CASE(ENAMETOOLONG);
	T_STRERROR_CASE(ENETDOWN);
	T_STRERROR_CASE(ENETRESET);
	T_STRERROR_CASE(ENETUNREACH);
	T_STRERROR_CASE(ENFILE);
	T_STRERROR_CASE(ENOBUFS);
#ifdef ENODATA
	T_STRERROR_CASE(ENODATA);
#endif
	T_STRERROR_CASE(ENODEV);
	T_STRERROR_CASE(ENOENT);
	T_STRERROR_CASE(ENOEXEC);
	T_STRERROR_CASE(ENOLCK);
	T_STRERROR_CASE(ENOLINK);
	T_STRERROR_CASE(ENOMEM);
	T_STRERROR_CASE(ENOMSG);
	T_STRERROR_CASE(ENOPROTOOPT);
	T_STRERROR_CASE(ENOSPC);
#ifdef ENOSR
	T_STRERROR_CASE(ENOSR);
#endif
#ifdef ENOSTR
	T_STRERROR_CASE(ENOSTR);
#endif
	T_STRERROR_CASE(ENOSYS);
	T_STRERROR_CASE(ENOTCONN);
	T_STRERROR_CASE(ENOTDIR);
	T_STRERROR_CASE(ENOTEMPTY);
	T_STRERROR_CASE(ENOTRECOVERABLE);
	T_STRERROR_CASE(ENOTSOCK);
#if ENOTSUP != EOPNOTSUPP
	T_STRERROR_CASE(ENOTSUP);
#endif
	T_STRERROR_CASE(ENOTTY);
	T_STRERROR_CASE(ENXIO);
	T_STRERROR_CASE(EOPNOTSUPP);
	T_STRERROR_CASE(EOVERFLOW);
	T_STRERROR_CASE(EOWNERDEAD);
	T_STRERROR_CASE(EPERM);
	T_STRERROR_CASE(EPFNOSUPPORT);
	T_STRERROR_CASE(EPIPE);
	T_STRERROR_CASE(EPROTO);
	T_STRERROR_CASE(EPROTONOSUPPORT);
	T_STRERROR_CASE(EPROTOTYPE);
	T_STRERROR_CASE(ERANGE);
	T_STRERROR_CASE(EROFS);
	T_STRERROR_CASE(ESPIPE);
	T_STRERROR_CASE(ESRCH);
	T_STRERROR_CASE(ESTALE);
#ifdef ETIME
	T_STRERROR_CASE(ETIME);
#endif
	T_STRERROR_CASE(ETIMEDOUT);
	T_STRERROR_CASE(ETOOMANYREFS);
	T_STRERROR_CASE(ETXTBSY);
	T_STRERROR_CASE(EXDEV);
	default:
		return "?";
	}
}

void T_check_eno(int a, const T_check_context *t, int e)
{
	T_check_true(a == e, t, "%s == %s", T_strerror(a), T_strerror(e));
}

void T_check_eno_success(int a, const T_check_context *t)
{
	T_check_eno(a, t, 0);
}
