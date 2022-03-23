import { HttpClientModule } from '@angular/common/http';
import { Component, OnInit } from '@angular/core';
import { Equation } from '../equation';
import { EquationService } from '../equation.service';

@Component({
  selector: 'app-expression-list',
  templateUrl: './expression-list.component.html',
  styleUrls: ['./expression-list.component.scss']
})
export class ExpressionListComponent implements OnInit {

  expressions: Equation[];

  constructor(private equationService: EquationService) {
    this.expressions = [];
  }

  ngOnInit(): void {
    this.equationService.getEquations().subscribe(
      equations => { this.expressions = equations; }
    )
  }

}
