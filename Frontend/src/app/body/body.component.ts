import { Component, OnInit } from '@angular/core';

@Component({
  selector: 'app-body',
  template: `

    <app-calculator-form></app-calculator-form>
    
  `,
  styles: []
})
export class BodyComponent implements OnInit {

  constructor() { }

  ngOnInit(): void {
  }

}
