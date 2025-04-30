let PrecioUnitario = prompt("ingrese el precio unitario");
let CantidadDeseada = prompt ("ingrse la cantidad");

function SumarProductos(PrecioUnitario,CantidadDeseada){

    total = PrecioUnitario*CantidadDeseada;
    alert("su total a pagar es de "+total);
}
SumarProductos(PrecioUnitario, CantidadDeseada);