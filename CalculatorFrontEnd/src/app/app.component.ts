import { Component, OnInit } from '@angular/core';

import { Equation, Reference } from './equation';
import { EquationService } from './equation.service';

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.scss']
})
export class AppComponent implements OnInit {
  title = 'Simon\'s Calculator';
  equations: Reference<Equation[] | null>;
  lastCalculation: Reference<Equation | null>;

  constructor(private equationService: EquationService) {
    this.equations = { value: [] };
    this.lastCalculation = { value: null };
  }

  ngOnInit(): void {
    this.equationService.getEquations().subscribe(
      equations => { this.equations.value = equations; }
    )
  }

  calculate(equation: Equation) {
    if(null != equation.id && null != equation.variables) {
      this.equationService.calculateEquation(equation.id, equation.variables).subscribe(
        calculation => { this.lastCalculation.value = calculation; }
      );
    }
  }
}
