# Aplicaciones-Android

APK con Build Release API 17 (4.2, 4.22) Android_for_armeabi_v7a_GCC_4_9_Qt_5_11_1_for_Android_armv7-Release<br>

Características<br>

-> 3 Matarías Independientes con la excepción de la base de datos.<br>
-> La base de datos contiene la tabla Alumnos que contiene AlumnoID (Clave primaria),Apellido, Nombre y MateriaID;La tabla Asistencias contiene la Tabla AsistenciaID (Clave primaria), Fecha, Estado, AlumnoID (clave secundaria) y MateriaID.<br>
-> Al Agregar/Editar un Alumno la aplicación no deja agregarlo si algún campo está vacío.<br>
-> Al Agregar/Editar un alumno si este ya existiera ([Existe]Nombre + Apellido = Nombre + Apellido[Otro alumno se edita o se agrega]) la aplicación nos va a alertar que ya existe.<br>
-> Al elegir la fecha la aplicación nos restringe al seleccionar un día mayor a 31 y un mes mayor a 12.<br>
-> Para ver las asistencias tiene un filtrado por alumno y por fecha, de ser erróneo o no existe la aplicación nos alerta.<br>
