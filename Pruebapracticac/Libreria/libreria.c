#include <stdio.h>

int main() {
    char continuar;

    do {
        char nombre[50];
        int cantidadLibros, metodoPago;
        char titulos[100][31]; 
        float precios[100];
        int cantidades[100];
        float subtotales[100];

        printf("\nIngrese el nombre del cliente : ");
        scanf("%s", nombre);  

        printf("Cantidad de libros a comprar: ");
        scanf("%d", &cantidadLibros);

        for (int i = 0; i < cantidadLibros; i++) {
            printf("\nLibro #%d\n", i + 1);
            printf("Titulo : ");
            scanf("%s", titulos[i]);

            printf("Precio unitario: Q");
            scanf("%f", &precios[i]);

            printf("Cantidad: ");
            scanf("%d", &cantidades[i]);

            subtotales[i] = precios[i] * cantidades[i];
        }

        float total = 0;
        for (int i = 0; i < cantidadLibros; i++)
            total += subtotales[i];

        float descuento = (total > 200) ? total * 0.15 : total * 0.05;

        printf("\nMetodo de pago (1: Efectivo | 2: Tarjeta): ");
        scanf("%d", &metodoPago);

        float recargo = (metodoPago == 2) ? (total - descuento) * 0.05 : 0;
        float totalFinal = (total - descuento) + recargo;

        printf("\n========== FACTURA ==========\n");
        printf("Cliente: %s\n", nombre);
        printf("\nLibros Comprados:\n");
        for (int i = 0; i < cantidadLibros; i++) {
            printf("Titulo: %s | Cantidad: %d | Precio: Q%.2f | Subtotal: Q%.2f\n",titulos[i], cantidades[i], precios[i], subtotales[i]);
        }

        printf("\nTotal sin descuento: Q%.2f", total);
        printf("\nDescuento aplicado: Q%.2f", descuento);
        printf("\nRecargo (si aplica): Q%.2f", recargo);
        printf("\nTOTAL FINAL A PAGAR: Q%.2f\n", totalFinal);
        printf("=============================\n");

        printf("\n¿Desea ingresar otra compra? (s/n): ");
        scanf(" %c", &continuar);

    } while (continuar == 's' || continuar == 'S');

    return 0;
}