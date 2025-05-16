// Crear un array de productos
let productos = [
  { nombre: "camisa", stock: 10 },
  { nombre: "Pantalón", stock: 5 },
  { nombre: "Zapatos", stock: 8 },
  { nombre: "Gorra", stock: 12 }
];

// Mostrar el contenido del array usando un bucle for
console.log("Lista de productos:");
for (let i = 0; i < productos.length; i++) {
  console.log(`Producto: ${productos[i].nombre}, Stock: ${productos[i].stock}`);
}

// Simular la venta de productos eliminando el último con pop()
for (let i = 0; i < 2; i++) { // simulamos 2 ventas
  let vendido = productos.pop(); // elimina el último producto del array
  console.log(`\nProducto vendido: ${vendido.nombre}`);
  console.log("Stock actualizado:");
  
  for (let j = 0; j < productos.length; j++) {
    console.log(`Producto: ${productos[j].nombre}, Stock: ${productos[j].stock}`);
  }
}
