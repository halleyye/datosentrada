    cout << "1. VIP\n";
    cout << "2. Estandar\n";
    cout << "Por favor, seleccione el numero correspondiente al tipo de servicio: \n";
    cin.getline(p[registro].servicio, MAX);
    limpiarBuffer();
    int opcion;
    cin >> opcion;
    switch (opcion)
    {
    case 1:
        strcpy(p[registro].servicio, "VIP\n");
        cout << "costo: 120$" << endl;
        break;
    case 2:
        strcpy(p[registro].servicio, "Estandar\n");
        cout << "costo 90$\n";
        break;
    default:
        cout << "Opcion invalida. Seleccionando servicio Estandar por defecto.\n";
        strcpy(p[registro].servicio, "Estandar\n");
    }
}

// fecha de la reservacion
void fechayhorareserva()
{
    cout << "Fecha en la que desea reservar: \n";
    cin.getline(p[registro].fechareserva, MAX);
    limpiarBuffer();
    cout << "Hora en la que desea su reserva: \n";
    cin.getline(p[registro].horareserva, MAX);
    limpiarBuffer();
}
// numero maximo de personas a llegar

void cantidadpersonas()
{
    cout << "Cantidad de personas a llegar: " << endl;
    cin.getline(p[registro].cantpersonas, 20);
    limpiarBuffer();
}
// verificacion de la cantidad maxima de personas
bool calcMAXpersonas()
{
    int cantmaxima = atoi(p[registro].cantpersonas);
    while (cantmaxima > 20)
    {
        cout << "Excede el limite de acceso de clientes disponible.\n";
        cout << "Por favor, vuelva a intentarlo con otro numero.";
        cin.getline(p[registro].cantpersonas, 20, '\n');
        cantmaxima = atoi(p[registro].cantpersonas);
    }
    return true;
}

// ejecucion final del codigo
int main()
{
    SetConsoleOutputCP(CP_UTF8);
    addcliente();
    ingcedula();
    calcEdad();
    numcel();
    tiposervicio();
    cantidadpersonas();
    calcMAXpersonas();
    fechayhorareserva();
    cout << "El cliente " << p[registro].nombre << " " << p[registro].apellidos << endl;
    cout << "Numero de cedula: " << p[registro].cedula << endl;
    cout << "Numero de celular: " << p[registro].numcelular << endl;
    cout << "Contrato el servicio " << p[registro].servicio << endl;
    cout << "arribando con " << p[registro].cantpersonas << "personas" << endl;
    cout << "El dia " << p[registro].fechareserva << " ";
    cout << "a las " << p[registro].horareserva << endl;

    return 0;
}

