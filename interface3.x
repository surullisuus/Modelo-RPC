
const TAM_MAX_NOM_ARCHIVO = 128;
const TAM_MAX_BLOQUE_ARCHIVO = 1024;


struct datosCalculados{
    int codigoCancion ;
    char titulo[TAM_MAX_NOM_ARCHIVO];
    char tipo[TAM_MAX_NOM_ARCHIVO];
    char autor [TAM_MAX_NOM_ARCHIVO];
    int peso;

}; typedef struct datosCalculados datosCalculados;


program programa_calcular_datos{
  version programa_calcular_datos_version3 {    
    int enviar_notificacion(datosCalculados objDatos)=1;
  } = 3;

  
} = 0x21000003;
