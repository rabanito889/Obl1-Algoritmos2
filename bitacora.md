# Bitácora — Obligatorio 1

**Integrantes:** Nombre Apellido (Nº estudiante), Nombre Apellido (Nº estudiante)

> **Instrucciones** (borrar esta sección antes de entregar): agregar una entrada por
> cada día trabajado, indicando la fecha y quién trabajó (un integrante o "En conjunto").
> Registrar el proceso real: ideas exploradas, decisiones y su justificación, partes de
> implementaciones, bugs encontrados y cómo se corrigieron, resultados de pruebas y dudas
> abiertas. Si se usó IA ese día, indicar herramienta, consulta y qué se hizo con la
> respuesta. Una bitácora escrita íntegramente el día de la entrega implica pérdida de puntos.

## 2026-09-09 — Rodrigo Charamelo
- Lei la letra del ejercicio uno, por lo visto hay que implementar un dos AVL, uno para las monedas y otro para las pinturas, lo mejor seguramente sea hacer uno generico en los TADs.
- Voy a basarme en lo hecho en la clase paractica de AVL
- Termine de hacer el TAD basico de AVL, me quedo practicamente igual al de la clase, no se que tan bien este, pedi ayuda a la IA para hacer el .h pero a verdad que no me convence, preguntare al profesor y veo que hago con ese archivo
- Termine de hacer el ejercicio, pense que seria mas dificl pero es una logica de casos muy sencilla
- El codigo por alguna razon no compila, hago el comando de g++, no me tira error pero no me genera los archivos
- llevo hace 1h buscando el problema, ya probe preguntando a la IA y no sabe ni ella, no se que hare.
- Bueno, le di control al agente de visual y me lo pudo soucionar despues de descargar 80 cosas, no se si cuenta como uso de IA ya que el error no era del codigo en si (no toco nada de los archivos).
- Tuve que cambiar el archivo .h de AVL por uno que contiene toda la implementacion, todo muy raro pero si no no me compilaba tampoco. me parece rarisima esta situacion. Solo me compila si pongo este comando exacto (junto):
- g++ -std=c++11 -Wall ejercicio1.cpp -o ejercicio1.exe
- ./ejercicio1.exe < tests/test_completo_ej1.in > mi_salida.txt"
- este comando me lo dio la IA, no tengo idea porque solo funciona asi, pero lo unico que se es que el codigo en si anda bien ya que hice varios tests
- Actualizacion: no anda mas con ese codigo, le tuve que mandar mensaje al profe a ver que puedo hacer, probe otras cosas y no pude. Seguire otro dia
- Actualizacion 2: no me podia ir asi nomas, segui luchando e investigando y di con lo que parece ser la solucion, tuve que "reeinstalar" g++ con la terminal msys2, no me soluciono lo de ejecutar en visual, pero al menos en la propia terminal de msys2 puedo poner los comandos y si me los ejecuta
- Tambien cambie el .h por el .cpp comun, quedo todo lo referido al TAD AVL en un archivo.
- QUE QUILOMBO DE BITACORA

## 2026-09-12 — Rodrigo Charamelo
- Leyendo el ejercicio 2, la letra parece sencilla, hay que implementar un hash abierto e ir guardando la cantidad de palabras registradas
- Estaba haciendo el TAD de hash y se me ocurrio que si organizo alfabeticamente las palabras es mucho mas sencillo respetar el orden
, tengo que usar una funcion que no vimos, asi que la busque en Google. esto no me va a afectar porque no tengo que devolver las palabras en ningun momento
- Ya termine y testee el ejercicio, me parecio mas sencillo que el anterior, mi complicacion esta en la sintaxis de class y de public y private pero ya le estoy agarrando la mano.
- Por alguna extraña razon, ahora g++ no me esta dando problemas, todo el estres del otro dia parece ser por nada jaja.

## 2026-09-20 — Rodrigo Charamelo
- Despues de unos dias, me dispongo a seguir con el ejercicio 3, ya lei la letra y hay que usar un Heap, voy a tener
que repasar los conceptos porque no me acuerdo bien que hacia
- Me voy a basar un poco en lo que implementamos en la clase de practico, lo voy a tener de referencia mas no quiero verlo porque si no no aprendo nada.
- Ya termine el TAD y el ejercicio, algun error tuve pero eran cosas chicas, por ahora el mas facil de los 3.
- Otra vez me dio problema g++, tuve que usar el terminal de msys2, pero al menos funciona todo el codigo.

## AAAA-MM-DD — En conjunto
- Ejemplo: Implementamos ... Bug: ... Lo corregimos ...
- Pasan los casos de prueba 1 a 4 del ejercicio 1.
