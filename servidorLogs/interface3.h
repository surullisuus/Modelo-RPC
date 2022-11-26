/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _INTERFACE3_H_RPCGEN
#define _INTERFACE3_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif

#define TAM_MAX_NOM_ARCHIVO 128
#define TAM_MAX_BLOQUE_ARCHIVO 1024

struct datosCalculados {
	int codigoCancion;
	char titulo[TAM_MAX_NOM_ARCHIVO];
	char tipo[TAM_MAX_NOM_ARCHIVO];
	char autor[TAM_MAX_NOM_ARCHIVO];
	int peso;
};
typedef struct datosCalculados datosCalculados;


#define programa_calcular_datos 0x21000003
#define programa_calcular_datos_version3 3

#if defined(__STDC__) || defined(__cplusplus)
#define enviar_notificacion 1
extern  int * enviar_notificacion_3(datosCalculados *, CLIENT *);
extern  int * enviar_notificacion_3_svc(datosCalculados *, struct svc_req *);
extern int programa_calcular_datos_3_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define enviar_notificacion 1
extern  int * enviar_notificacion_3();
extern  int * enviar_notificacion_3_svc();
extern int programa_calcular_datos_3_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_datosCalculados (XDR *, datosCalculados*);
extern  bool_t xdr_datosCalculados (XDR *, datosCalculados*);

#else /* K&R C */
extern bool_t xdr_datosCalculados ();
extern bool_t xdr_datosCalculados ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_INTERFACE3_H_RPCGEN */