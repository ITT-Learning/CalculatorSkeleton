import { HttpClientModule } from '@angular/common/http';
import { Component, Input, OnInit } from '@angular/core';

import { Equation } from '../equation';
import { EquationService } from '../equation.service';
import { Reference } from '../reference';

@Component({
  selector: 'app-expression-list',
  templateUrl: './expression-list.component.html',
  styleUrls: ['./expression-list.component.scss']
})
export class ExpressionListComponent implements OnInit {

  @Input()
  equations: Reference<Equation[]>;

  @Input()
  lastCalculation: Reference<Equation | null>;

  constructor(private equationService: EquationService) {
    this.equations = { value: [] };
    this.lastCalculation = { value: null };
  }

  ngOnInit(): void {
  }

  onClickCalculate(equation: Equation): void {
    if(null != equation.id && null != equation.variables)
    {
      this.equationService.calculateEquation(equation.id, equation.variables);
    }
  }
}
