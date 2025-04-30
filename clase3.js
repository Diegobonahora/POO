let NombreProdcuto = prompt("ingrese nombre del producto");
let PrecioProducto = 500;
let CantidadDeseada = prompt("ingrese la cant");

if(CantidadDeseada >= 5){
    descuento= (PrecioProducto*CantidadDeseada) * 0.10;
        TotalAPagar = (PrecioProducto*CantidadDeseada)-descuento;

        alert(`Su total es ${TotalAPagar} por el producto ${NombreProdcuto}`);
}
else{
    alert(`Su total es ${PrecioProducto*CantidadDeseada} por el producto ${NombreProdcuto}`);
}
