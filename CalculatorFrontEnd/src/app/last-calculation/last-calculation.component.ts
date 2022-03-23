import { Component, OnInit } from '@angular/core';

import { Equation } from '../equation';

@Component({
  selector: 'app-last-calculation',
  templateUrl: './last-calculation.component.html',
  styleUrls: ['./last-calculation.component.scss']
})
export class LastCalculationComponent implements OnInit {

  lastCalculation: Equation | null;

  constructor() {
    this.lastCalculation = null;
  }

  ngOnInit(): void {
  }

}
