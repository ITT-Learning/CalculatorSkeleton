import { Component, Input, OnInit } from '@angular/core';

import { Equation, Reference } from '../equation';
import { EquationService } from '../equation.service';

@Component({
  selector: 'app-save-expression',
  templateUrl: './save-expression.component.html',
  styleUrls: ['./save-expression.component.scss']
})
export class SaveExpressionComponent implements OnInit {

  @Input()
  equations: Reference<Equation[]>;

  newEquationInput: string;

  constructor(private equationService: EquationService) {
    this.equations = { value: [] };
    this.newEquationInput = '';
  }

  ngOnInit(): void {
  }

  onClickSaveNewEquation(): void {
    this.equationService.storeEquation(this.newEquationInput).subscribe(
      newEquation => {
        if(null != newEquation) {
          this.equations.value.push(newEquation);
        }
      }
    );
  }
}
