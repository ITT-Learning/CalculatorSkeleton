import { Component, Input, OnInit } from '@angular/core';

import { Equation } from '../equation';
import { Reference } from '../reference';

@Component({
  selector: 'app-last-calculation',
  templateUrl: './last-calculation.component.html',
  styleUrls: ['./last-calculation.component.scss']
})
export class LastCalculationComponent implements OnInit {

  @Input()
  lastCalculation: Reference<Equation | null>;

  constructor() {
    this.lastCalculation = { value: null };
  }

  ngOnInit(): void {
  }

}
