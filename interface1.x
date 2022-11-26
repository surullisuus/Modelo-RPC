const TAM_MAX_NOM_ARCHIVO = 128;
const TAM_MAX_BLOQUE_ARCHIVO = 1024;

struct bloque {
    string nombreArchivo<TAM_MAX_NOM_ARCHIVO>;
    opaque datos<TAM_MAX_BLOQUE_ARCHIVO>;
    int size;
    int dest_offset;
};
typedef struct bloque bloque;

struct nodo_cancion
{
int codigoCancion ;
char titulo[TAM_MAX_NOM_ARCHIVO];
char tipo[TAM_MAX_NOM_ARCHIVO];
char autor [TAM_MAX_NOM_ARCHIVO];
int peso;
};
program programa_compartir_canciones {
  version programa_compartir_canciones_version_1 {    
  int crearArchivo(string archivo) = 1;    
  int enviarArchivo(bloque *) = 2;   
  bool registrarCancion(nodo_cancion objCancion)=3;
  nodo_cancion consultarCancion(string titulo)=4; 
  } = 1;

  
} = 0x21000001;
