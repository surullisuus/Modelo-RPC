/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "interface2.h"
#include <stdio.h>
#include <stdlib.h>
#include <rpc/pmap_clnt.h>
#include <string.h>
#include <memory.h>
#include <sys/socket.h>
#include <netinet/in.h>

#ifndef SIG_PF
#define SIG_PF void(*)(int)
#endif

static void
programa_compartir_canciones2_2(struct svc_req *rqstp, register SVCXPRT *transp)
{
	union {
		char *crearcopiaarchivo_2_arg;
		bloque2 enviarcopiaarchivo_2_arg;
	} argument;
	char *result;
	xdrproc_t _xdr_argument, _xdr_result;
	char *(*local)(char *, struct svc_req *);

	switch (rqstp->rq_proc) {
	case NULLPROC:
		(void) svc_sendreply (transp, (xdrproc_t) xdr_void, (char *)NULL);
		return;

	case crearCopiaArchivo:
		_xdr_argument = (xdrproc_t) xdr_wrapstring;
		_xdr_result = (xdrproc_t) xdr_int;
		local = (char *(*)(char *, struct svc_req *)) crearcopiaarchivo_2_svc;
		break;

	case enviarCopiaArchivo:
		_xdr_argument = (xdrproc_t) xdr_bloque2;
		_xdr_result = (xdrproc_t) xdr_int;
		local = (char *(*)(char *, struct svc_req *)) enviarcopiaarchivo_2_svc;
		break;

	default:
		svcerr_noproc (transp);
		return;
	}
	memset ((char *)&argument, 0, sizeof (argument));
	if (!svc_getargs (transp, (xdrproc_t) _xdr_argument, (caddr_t) &argument)) {
		svcerr_decode (transp);
		return;
	}
	result = (*local)((char *)&argument, rqstp);
	if (result != NULL && !svc_sendreply(transp, (xdrproc_t) _xdr_result, result)) {
		svcerr_systemerr (transp);
	}
	if (!svc_freeargs (transp, (xdrproc_t) _xdr_argument, (caddr_t) &argument)) {
		fprintf (stderr, "%s", "unable to free arguments");
		exit (1);
	}
	return;
}

int
main (int argc, char **argv)
{
	register SVCXPRT *transp;

	pmap_unset (programa_compartir_canciones2, programa_compartir_canciones_version_2);

	transp = svcudp_create(RPC_ANYSOCK);
	if (transp == NULL) {
		fprintf (stderr, "%s", "cannot create udp service.");
		exit(1);
	}
	if (!svc_register(transp, programa_compartir_canciones2, programa_compartir_canciones_version_2, programa_compartir_canciones2_2, IPPROTO_UDP)) {
		fprintf (stderr, "%s", "unable to register (programa_compartir_canciones2, programa_compartir_canciones_version_2, udp).");
		exit(1);
	}

	transp = svctcp_create(RPC_ANYSOCK, 0, 0);
	if (transp == NULL) {
		fprintf (stderr, "%s", "cannot create tcp service.");
		exit(1);
	}
	if (!svc_register(transp, programa_compartir_canciones2, programa_compartir_canciones_version_2, programa_compartir_canciones2_2, IPPROTO_TCP)) {
		fprintf (stderr, "%s", "unable to register (programa_compartir_canciones2, programa_compartir_canciones_version_2, tcp).");
		exit(1);
	}

	svc_run ();
	fprintf (stderr, "%s", "svc_run returned");
	exit (1);
	/* NOTREACHED */
}
