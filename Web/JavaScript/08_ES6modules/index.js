/*
With modules, we can import sections of a pre-written code to use whenever.
*/ 


/* to import, you can select export by export like below, or import everything with a "*"

import {PI, CircleCircunference, CircleArea} from "./math_utilities.js"
*/

import * as MathUtil from "./math_utilities.js"

console.log(MathUtil.PI);

let circunference = MathUtil.CircleCircunference(20);
console.log(circunference);

let area = MathUtil.CircleArea(20);
console.log(area);