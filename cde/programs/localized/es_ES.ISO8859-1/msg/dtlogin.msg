$ "$XConsortium: dtlogin.msg /main/12 1996/12/20 15:05:02 rws $"    
$ *************************************<+>*************************************    
$ *****************************************************************************    
$ **    
$ **  File:        dtlogin.msg    
$ **    
$ **  Project:     CDE dtlogin    
$ **    
$ **  Description:    
$ **  -----------    
$ **  This file is the source for the message catalog for dtlogin    
$ **    
$ **    
$ *****************************************************************************    
$ **    
$ **     (c) Copyright 1990 Hewlett-Packard Company    
$ **     All Rights reserved    
$ **    
$ **    
$ *****************************************************************************    
$ **    
$ **    
$ **  ------------------------- MODIFICATION RECORD --------------------------    
$ *    
$ *     
$ **  ----------------------- MODIFICATION RECORD END ------------------------    
$ *****************************************************************************    
$ *************************************<+>*************************************    
$ *************************************<L>*************************************    
$ **  -----------------GENERAL LOCALIZATION NOTES SECTION---------------------    
$ * Comment lines begin with a $ except $set which indicates the start of a     
$ * new set.    
$ *    
$ * Do not delete any comments; you may add comments for your use.    
$ *    
$ **  ----------------GENERAL LOCALIZATION NOTES SECTION END------------------    
$ *************************************<L>*************************************    
$quote "

$set 1
$ set 1 is labels    
$     
$ messages 1 through 6 are button labels on the login screen    

1 "Por favor, entre su nombre de usuario"

2 "Por favor, entre su contrase�a"

3 "OK"

4 "Iniciar "

5 "Opciones"

6 "Ayuda"
$     
$ messages 7 through 11 are options button menu items    
$     

7 "Restablecer pantalla inicio de sesi�n"

8 "Inicio de sesi�n l�nea de mandatos"

9 "Versi�n..."

10 "Sesi�n de ventana �nica"

11 "Idioma"
$     
$ messages 12 through 14 are miscellaneous button labels    
$     

12 "Iniciar DT"

13 "Cancelar"

14 "Ayuda"
$     
$ message 15, 17 are more option button menu items     
$ message 16 is the welcome message    
$     

15 "Sesi�n Lite DT "

16 "Bienvenido a"

17 "Escritorio normal"
$     
$ message 18-24    
$     

18 "* Suspendiendo inicio de sesi�n del escritorio...\r\n\
*\r\n"

19 "* Pulse [Intro] para obtener una solicitud de inicio de sesi�n.\r\n\
*\r\n"

20 "* Inicio de sesi�n. El inicio de sesi�n del escritorio se reanudar� \r\n\
* en breve despu�s de finalizar la sesi�n.\r\n\
*\r\n"

21 "* Reanudando el inicio de sesi�n del escritorio...\r\n\
*\r\n"

22 "* Iniciando la sesi�n del escritorio en la pantalla %1$s...\r\n\
*\r\n"

23 "* Espere a la pantalla de inicio de sesi�n del escritorio antes de iniciar la sesi�n.\r\n\
*\r\n"

24 "* El servidor de X no se puede iniciar en la pantalla %1$s...\r\n\
*\r\n"
$ messages 25 is a options button menu item    

25 "Sesi�n"
$     
$ 26 replaces 16 as the greeting after a user name has been     
$ entered. The %s is replaced by the user name.    
$     

26 "Bienvenido, %s"

$ 
$ 27 replaces 10 as the label for the failsafe option menu item
$ 
$quote

27 Sesi�n a prueba de fallos

$ 
$  Sun specific message catalog id numbers in MC_LABEL_SET messages.
$  (Starting at a random uneven higher number, 73, to allow some room  
$  for some shared sample source message additions. 
$ 
73 Ultimo escritorio del usuario
$ 
$  Following used in Language menu.  
$  "to" used in phrases like "ja to zh" locales
74 a


$set 2

$ set 2 is error messages    
$     

$quote "
1 "Inicio de sesi�n incorrecto; int�ntelo de nuevo."

2 "No se puede cambiar al directorio inicio."

3 "Lo siento. Ya est�n conectados el n�mero m�ximo de usuarios."
$ message 4 is a lengthy message that should be localized to correspond to     
$ the language.      

4 "\n\
Tiene que elegir una contrase�a inicial para su cuenta,\n\
o bien su contrase�a actual ha caducado.\n\n\
Despu�s de establecer su contrase�a, debe iniciar de nuevo \n\
la sesi�n utilizando la nueva contrase�a."

5 "Error de inicio de sesi�n, id de usuario no v�lido."

6 "Error de inicio de sesi�n, id de grupo no v�lido."

7 "Error de inicio de sesi�n, id de comprobaci�n no v�lido."

8 "Error de inicio de sesi�n, distintivo de comprobaci�n no v�lido."

9 "Los inicios de sesi�n est�n inhabilitados en este momento."

10 "S�lo root desea ejecutar %1$s\n"

11 "Reconstruyendo la lista de idiomas por omisi�n a partir de %1$s\n"

12 "Volviendo a explorar los archivos de configuraci�n y de servidores\n"

13 "Releyendo el archivo de configuraci�n %1$s\n"

14 "Releyendo el archivo de servidores %1$s\n"

15 "Releyendo el archivo de acceso %1$s\n"

16 "dtlogin: sin memoria en la rutina\n"

$set 3

$ set 3 is help text    
$     
$ message 1 is generated when the help button on the login screen is clicked.
$ Comments for messsage #1:
$ 
$ Under [Options] there is an item called "Session".  Under
$ Session there are five items and these items have been
$ translated in other files.  To be consistent with the other
$ translations, the translations used below should be the same
$ as the other translations.  The items and their file are
$ listed below:
$ 
$   1. Current   - _common.session.tmsg ; set 1, message 2
$ 
$   2. Home      - _common.session.tmsg ; set 1, message 1
$ 
$   3. <display-name> - Current   - <display-name> on the options
$         menu will be replaced with the workstations display
$         name so does not need to be translated.  "Current" should
$         be the same as _common.session.tmsg ; set 1, message 2
$ 
$   4. <display-name> - Home      - <display-name> on the options
$         menu will be replaced with the workstations display
$         name so does not need to be translated.  "Home" should
$         be the same as _common.session.tmsg ; set 1, message 1
$ 
$ 
1 "\n\
Ayuda para Inicio de sesi�n:\n\
\n\
Utilice la pantalla conexi�n para identificarse frente al sistema.\n\
\n\
Para iniciar la sesi�n:\n\
       1) Escriba su nombre y pulse <Intro> o haga clic [OK].\n\
          (si no ha creado un usuario, utilice \"root\" como\n\
          nombre de usuario)\n\
       2) Escriba su contrase�a y pulse <Intro> o haga clic [OK].\n\
\n\
[Iniciar]\n\
   Borra las entradas de modo que pueda volver a introducir el nombre\n\
  de usuario e intentar la operaci�n de nuevo\n\
\n\
[Opciones]\n\
   Le permite modificar las opciones de sesi�n:\n\
\n\
   Con el puntero del rat�n sobre el bot�n [Optiones], mantenga\n\
   pulsado el bot�n 1 del rat�n. Arrastre el puntero a trav�s de\n\
   las opciones. Al liberar el bot�n del rat�n con el puntero\n\
   sobre un elemento, �ste se seleccionar�. Puede escoger:\n\
\n\
   Idioma - para cambiar el idioma de sesi�n\n\
   Sesi�n - para seleccionar un entorno gr�fico\n\
      Actual - Activa su sesi�n m�s reciente\n\
      Inicio - Activa su sesi�n de inicio (si ha especificado una)\n\
      <nombre de pantalla> - Actual - Activa su sesi�n m�s reciente para\n\
          la pantalla especificada\n\
      <nombre de pantalla> - Inicio - Activa su sesi�n de inicio para\n\
          la pantalla especificada\n\
      Sesi�n a prueba de fallos - Activa una sesi�n a prueba de fallos.\n\
 Inicio de Sesi�n de L�nea de Mandatos - para conmutar a un entorno de l�nea de mandatos.\n\
 Restaurar Pantalla de Inicio de Sesi�n - para restaurar el servidor X.\n\
\n\
Pulse sobre cualquier lugar del fondo con cualquier bot�n del rat�n\n\
para renovar la pantalla, por ejemplo, en caso de que los mensajes\n\
del sistema hagan que la pantalla resulte ilegible.\n\
\n\
Para obtener m�s informaci�n de ayuda, primero inicie la sesi�n y luego\n\
pulse el icono Gestor de Ayuda del Panel Frontal (son los libros con\n\
interrogante).\n\
A continuaci�n, busque el volumen de ayuda del Gestor de Inicio de sesi�n.\n"


$ message 2 is generated when you attempt to start a system whose id is    
$ set to unknown or if it is not configured for networking.    

2 "\n\
La estaci�n de trabajo no tiene un nombre exclusivo. Actualmente est�\n\
establecido en \"desconocida\". Es aconsejable darle un nombre a esta \n\
estaci�n de trabajo.\n\n"
$ message 3 is generated when the help button on the chooser screen is clicked.    

3 "\n\
Ayuda  para el selector:\n\n\
Utilice la pantalla del selector para elegir el servidor en\n\
el que va a iniciar la sesi�n.\n\n\
La pantalla del selector contiene una lista con 2 partes para cada\n\
entrada. La primera parte (Nombre de servidor) contiene el nombre\n\
en la red para cada servidor disponible. La segunda parte (Informaci�n\n\
de servidor) contendr� informaci�n diferente seg�n el gestor de inicio\n\
de sesi�n que se ejecute en cada servidor. Si el servidor est� ejecutando\n\
el escritorio CDE, debe proporcionar informaci�n acerca de los usuarios\n\
(o dispositivos tty) que se utilizan en este momento y de los promedios de\n\
carga (promedio de utilizaci�n de CPU) de los �ltimos 5, 10 y 15 minutos.\n\n\
Para elegir un servidor para el inicio de sesi�n, seleccione la l�nea\n\
de la lista que contenga el nombre del servidor que desee.\n\n\
Cuando haya realizado su selecci�n, pulse el bot�n OK.\n\
Se mostrar� una pantalla de inicio de sesi�n del servidor \n\
que haya seleccionado.\n\n\
[Actualizar lista]\n\
   Borrar� la lista y volver� a crearla consultanto a los servidores\n\
   de la red si van a permitir inicios de sesi�n.\n\n\
[Opciones]\n\
   Permite cambiar las opciones de la sesi�n:\n\n\
   Con el puntero del rat�n sobre el bot�n [Opciones], pulse y mantenga\n\
   pulsado el bot�n 1 del rat�n. Arrastre el puntero sobre las opciones.\n\
   Cuando libere el bot�n del rat�n con el puntero sobre un elemento,\n\
   se seleccionar� dicho elemento. Puede elegir:\n\n\
   Idioma - para cambiar el idioma de la sesi�n\n\
   Restablecer pantalla de inicio de sesi�n - para rearrancar el servidor de X\n\n\
Pulse cualquier bot�n del rat�n en el fondo para refrescar\n\
la pantalla, por ejemplo, si no se puede leer a causa de \n\
los mensajes del sistema.\n\n"

$set 4

$ set 4 is log error messages    
$     

1 "Archivo de acceso \"%1$s\", host \"%2$s\" no hallado\n"

2 "ReadHostEntry\n"

3 "Archivo de acceso %1$s, pantalla %2$s desconocida\n"

4 "No se puede abrir el archivo control de acceso %1$s, no se otorgar�n peticiones XDMCP\n"

5 "Error de autentificaci�n de Domain/OS: %1$s (%2$s/%3$s)"

6 "No se puede abrir el archivo de autorizaciones de servidor %1$s\n"

7 "No se puede grabar el archivo de autorizaciones de servidor %1$s\n"

8 "saveAddr"

9 "Problemas al obtener la configuraci�n de la interfaz de red"

10 "setAuthNumber"

11 "No se puede bloquear el archivo de autorizaciones %1$s o la copia de seguridad %2$s\n"

12 "No se puede mover la autorizaci�n al sitio \n"

13 "No se puede crear/bloquear el archivo de pid %1$s\n"

14 "No se puede bloquear el archivo de pid %1$s, se est� ejecutando otro Dtlogin (pid %2$d)\n"

15 "No se puede acceder al archivo de servidores %1$s\n"

16 "NewDisplay"

17 "No se puede abrir el Archivo de Registro de Errores %1$s\n"

18 "TrimErrorLog(): el tama�o m�ximo del archivo de registro de errores es de 200Kb.\n"

19 "Falta nombre de pantalla en el archivo de servidores\n"

20 "Falta tipo de pantalla para %1$s\n"

21 "El nombre de host %1$s no es v�lido. Se establece DISPLAY en ':0'\n"

22 "Tipo de pantalla %1$s inaceptable para la pantalla %2$s\n"

23 "Tiempo excedido de pseudo-restauraci�n.\n"

24 "GetResource"

25 "no hay espacio para reasignar argumento\n"

26 "No se puede abrir el archivo de configuraci�n %1$s\n"

27 "Argumentos adicionales en la l�nea de mandatos:"

28 "StartServer(): sin argumentos\n"

29 "No se puede ejecutar el servidor %1$s\n"

30 "Ha fallado fork de StartServer(), latente\n"

31 "El servidor muri� inesperadamente\n"

32 "Se cuelga en intento #%2$d de XOpenDisplay(%1$s), se cancela.\n"

33 "Ha fallado el intento #%1$d de abrir el servidor para %2$s, abandonando\n"

34 "Error grave de E/S %d (%1$s)\n"

35 "Error X \n"

36 "Ha fallado inicio de sesi�n\n"

37 "AVISO: no se pudo proteger la pantalla %1$s \n"

38 "AVISO: no se pudo proteger el teclado de la pantalla %1$s\n"

39 "BLS - No se pudo obtener informaci�n de contabilidad.\n"

40 "BLS - No se pudo obtener informaci�n de contabilidad protegida.\n"

41 "BLS - No se pudo verificar el nivel de seguridad.\n"

42 "BLS - No se pudo cambiar al usuario: %1$s.\n"

43 "AFS - anomal�a de setgroups() al iniciar la sesi�n\n"

44 "Ha fallado setuid para el usuario %s, n�merr = %d\n"

45 "No hay directorio inicio %1$s para el usuario %2$s, se usa /\n"

46 "Ha fallado la ejecuci�n de la sesi�n %1$s\n"

47 "La sesi�n no tiene mandato/argumentos\n"

48 "No se puede iniciar una sesi�n para %s, ha fallado fork\n"

49 "Dtlogin no puede matar un cliente\n"

50 "No se puede ejecutar %1$s\n"

51 "No se puede hacer fork para ejecutar %1$s\n"

52 "Nombre de autentificaci�n \"%1$s\" inadecuado. Use AFS, Kerberos o el nombre por omisi�n.\n"

53 "No se puede ejecutar Dtgreet %1$s para %2$s\n"

54 "No se puede hacer fork para ejecutar Dtgreet %1$s\n"

55 "Ha fallado la creaci�n de z�calo en la boca %1$d\n"

56 "error al vincular la direcci�n de z�calo %1$d, n�merr = %2$d\n"

57 "makeEnv"

58 "setEnv"

59 "parseArgs"

60 "Exploraci�n de directorio %1$s supera los %2$d segundos. Termina la exploraci�n...\n"

61 "%s pertenece a m�s de %1$d grupos, se ignora %2$s \n"

62 "error de audwrite(): el llamador no es un superusuario\n"

63 "error de audwrite(): n�mero de suceso no v�lido en registro de comprobaci�n.\n"

64 "error de audwrite(): n�merr = %1$d\n"

65 "anomal�a en autentificaci�n de AFS: %1$s\n"

66 "La cuenta para %1$s ha caducado. Consulte al Administrador del Sistema.\n"

67 "Servidor muerto  %1$s\n"

68 "No se puede abrir el archivo de mapa de bits de logo: %1$s\n"

69 "no se puede leer el cat�logo de mensajes \"%1$s\". Se usa el idioma por omisi�n."

70 "no se pudo inicializar la pantalla %1$s, el servidor puede estar bajo control.\n"

71 "(%1$s): La anchura de reborde de inicio de sesi�n sobrepasa la pantalla, se usa la anchura por omisi�n.  Las unidades de reborde son p�xels.\n"

72 "(%1$s) La altura de reborde del inicio de sesi�n sobrepasa la pantalla, se usa la altura por omisi�n.  Las unidades de reborde son p�xels.\n"

$set 5

$ set 5 is for other stuff specific to chooser.    

1 "Seleccionar un servidor para el inicio de sesi�n:"
$ 1 is the title/instructions for the chooser dialog    

2 "Nombre de servidor             Informaci�n de servidor"
$                                ^    
$                                | This needs to start in this column    
$ 2 is the headings for the list    

3 "Actualizar lista"

$set 99

$    DO NOT TRANSLATE THESE MESSAGES    
$    DO NOT CHANGE THESE MESSAGES    
$    DO NOT LOCALIZE THESE MESSAGES    
$    These messages are used for the version information.    

1 "@(#)version_goes_here"

2 "\n\
@(#)_DtMessage catalog source $XConsortium: dtlogin.msg /main/12 1996/12/20 15:05:02 rws $"
