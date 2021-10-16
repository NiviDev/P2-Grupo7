#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#define RAL 1
#define RAC 2
#define ABB 3

void menu(RALineal *ral, RACuadratico *rac, ArbolBB *abb, int tipo);

void menu(RALineal *ral, RACuadratico *rac, ArbolBB *abb, int tipo){
    int opc = 1, cantidadArt, exito;
    char codigoAlta[10], codigoBaja[10], codigoEvocar[10], codigoPertenece[10],tipoArt[22],marcaArt[32],descripcionArt[102];
    float precioArt;
    Articulo articulo1, articulo2;
    while((opc<7)||(opc>=0)){
        system("cls");
        if (tipo == RAL)
            printf("\n\t\tREBALSE ABIERTO LINEAL\n\n");
        else if (tipo == RAC)
            printf("\n\t\tREBALSE ABIERTO CUADRATICO\n\n");
        else
            printf("\n\t\tARBOL BINARIO DE BUSQUEDA\n\n");
        /*-----------------------Menu de opciones-----------------------*/
        printf("\t\t1 - Ingreso de nuevos articulos.\n\n\t\t2 - Eliminacion de articulos existentes.\n\n\t\t3 - Consulta de articulos.\n\n\t\t4 - Mostrar Estructura.\n\n\t\t5 - Memorizacion Previa.\n\n\t\t6 - Volver.\n\n\n\t\tIngrese la opcion: ");
        fflush(stdin);
        scanf("%d",&opc);
        if(opc==6)
            break;
        /*-----------------------Repeticion en caso de entrada incorrecta-----------------------*/
        while((opc>5)||(opc<=0)){
            system("cls");
            printf("\n\t\tOpcion invalida, ingrese nuevamente");
            if (tipo == RAL)
                printf("\n\t\tREBALSE ABIERTO LINEAL\n\n");
            else if (tipo == RAC)
                printf("\n\t\tREBALSE ABIERTO CUADRATICO\n\n");
            else
                printf("\n\t\tARBOL BINARIO DE BUSQUEDA\n\n");
            printf("\t\t1 - Ingreso de nuevos articulos.\n\n\t\t2 - Eliminacion de articulos existentes.\n\n\t\t3 - Consulta de articulos.\n\n\t\t4 - Mostrar Estructura.\n\n\t\t5 - Memorizacion Previa.\n\n\t\t6 - Volver.\n\n\n\t\tIngrese la opcion: ");
            fflush(stdin);
            scanf("%d",&opc);
        }
        getchar();
        /*-----------------------Switch de opciones-----------------------*/
        switch(opc){
            /********
              ALTA
            *********/
            case 1:{
                if((tipo == RAL && ral->cantidad == M_RAL) || (tipo == RAC && rac->cantidad == M_RAC)){
                    system("cls");
                    printf("\n\t\tNo hay suficiente espacio para cargar un nuevo articulo\n");
                    system("pause");
                    break;
                }else{
                    do{
                        system("cls");
                        printf("\n\t\tIngrese los datos del nuevo articulo\n\n\t\tCodigo del Producto (8 digitos): ");
                        fflush(stdin);
                        scanf("%10[^\n]",&codigoAlta);
                        getchar();
                        toUpper(codigoAlta);
                    }while(strlen(codigoAlta)!=8);
                    strcpy(articulo1.codigo,codigoAlta);
                    //Ingresar tipo de articulo
                    printf("\n\t\tIngrese el tipo de articulo: ");
                    scanf("%22[^\n]",&tipoArt);
                    getchar();
                    strcpy(articulo1.tipo,tipoArt);
                    //Ingresar Marca
                    printf("\n\t\tIngrese la marca del articulo: ");
                    scanf("%32[^\n]",&marcaArt);
                    getchar();
                    strcpy(articulo1.marca,marcaArt);
                    //Ingresar Descripcion
                    printf("\n\t\tIngrese la descripcion del articulo: ");
                    scanf("%102[^\n]",&descripcionArt);
                    getchar();
                    strcpy(articulo1.descripcion,descripcionArt);
                    //Ingresar Precio
                    printf("\n\t\tIngrese el precio del articulo: ");
                    scanf("%f",&precioArt);
                    getchar();
                    articulo1.precio = precioArt;
                    //Ingresar cantidad en stock
                    printf("\n\t\tIngrese la cantidad en stock de este articulo: ");
                    scanf("%d",&cantidadArt);
                    getchar();
                    articulo1.cantidad = cantidadArt;
                    /*-----------------------Ejecucion de las altas-----------------------*/
                    if(tipo == RAL)
                        altaRAL(ral, articulo1, &exito);
                    else if(tipo == RAC)
                        altaRAC(rac, articulo1, &exito);
                    else
                        exito = altaABB(abb, articulo1);
                    system("cls");
                    if(exito == 1)
                        printf("\nAlta Exitosa.\n");
                    else
                        printf("\nEl articulo con codigo %s ya se encuentra cargado en el sistema.\n", articulo1.codigo);
                    system("pause");
                }
                break;
            }
            /********
              BAJA
            *********/
            case 2:{
                if((tipo == RAL && ral->cantidad > 0) || (tipo == RAC && rac->cantidad > 0) || (tipo == ABB && abb->cantArticulos > 0)){
                    printf("\n\t\tIngrese el codigo del articulo que desea eliminar\n\t\tCodigo (8 digitos): ");
                    scanf("%10[^\n]",&codigoBaja);
                    getchar();
                    toUpper(codigoBaja);
                    if(tipo == RAL)
                        bajaRAL(ral, codigoBaja, &exito);
                    else if(tipo == RAC)
                        bajaRAC(rac, codigoBaja, &exito);
                    else
                        exito = bajaABB(abb, codigoBaja);
                    if(exito == 1){
                        system("cls");
                        printf("\nSe elimino correctamente.\n");
                        system("pause");
                    }
                    else{
                        system("cls");
                        if(exito == 2)
                            printf("\nCancelo la eliminacion.\n");
                        else
                            printf("\nNo se encuentra el articulo con ese codigo.\n");
                        system("pause");
                    }
                    break;
                }else{
                    system("cls");
                    printf("\n\t\tEstructura vacia.\n");
                    system("pause");
                    break;
                }
            }
            /********
              EVOCAR
            *********/
            case 3:{
                if((tipo == RAL && ral->cantidad > 0) || (tipo == RAC && rac->cantidad > 0) || (tipo == ABB && abb->cantArticulos > 0)){
                    printf("\n\t\tIngrese el codigo del producto que esta buscando.\n\t\tCodigo (8 digitos): ");
                    scanf("%10[^\n]",&codigoEvocar);
                    toUpper(codigoEvocar);
                    if(tipo == RAL)
                        evocarRAL((*ral), codigoEvocar, &exito, &articulo2);
                    else if(tipo == RAC)
                        evocarRAC(rac, codigoEvocar, &exito, &articulo2);
                    else{
                        strcpy(articulo2.codigo,codigoEvocar);
                        exito = evocarABB(abb, &articulo2);
                    }
                    if(exito == 1){
                        mostrarArticulo(articulo2);
                        system("pause");
                        break;
                    }
                    else{
                        printf("\n\t\tNo se encontro el articulo con el codigo %s\n", codigoEvocar);
                        system("pause");
                        break;
                    }
                }else{
                    system("cls");
                    printf("\n\t\tEstructura vacia\n");
                    system("pause");
                    break;
                }
            }
            /********
              MOSTRAR ESTRUCTURA
            *********/
            case 4:{
                if((tipo == RAL && ral->cantidad > 0) || (tipo == RAC && rac->cantidad > 0) || (tipo == ABB && abb->cantArticulos > 0)){
                    system("cls");
                    if((tipo == RAL && ral->cantidad > 0) || (tipo == RAC && rac->cantidad > 0) || (tipo == ABB && abb->cantArticulos > 0)){
                        if(tipo == RAL)
                            mostrarRA(ral->rebalse, M_RAL);
                        else if(tipo == RAC)
                            mostrarRA(rac->rebalse, M_RAC);
                        else
                            mostrarTodoABB(abb);
                    }
                }else{
                    system("cls");
                    printf("\n\t\tEstructura vacia\n");
                    system("pause");
                }
                break;
            }
            /********
              MEMORIZACION PREVIA
            *********/
            case 5:{
                memorizacion(ral, rac, abb, tipo);
                break;
            }
        }
    }
}

#endif // MENU_H_INCLUDED
