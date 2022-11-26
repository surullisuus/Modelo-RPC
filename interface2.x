const TAM_MAX_NOM_ARCHIVO = 128;
const TAM_MAX_BLOQUE_ARCHIVO = 1024;

struct bloque2 {
    string nombreArchivo<TAM_MAX_NOM_ARCHIVO>;
    opaque datos<TAM_MAX_BLOQUE_ARCHIVO>;
    int size;
    int dest_offset;
};
typedef struct bloque2 bloque2;


program programa_compartir_canciones2 {
  version programa_compartir_canciones_version_2 {    
  int crearCopiaArchivo(string archivo) = 1;    
  int enviarCopiaArchivo(bloque2 *) = 2;   
  
  } = 2;

  
} = 0x21000002;
