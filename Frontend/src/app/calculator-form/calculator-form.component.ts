import { Component, OnInit } from '@angular/core';
import { FormBuilder } from '@angular/forms';

import { HttpClient, HttpErrorResponse } from '@angular/common/http';
import { catchError, throwError } from 'rxjs';

@Component({
  selector: 'app-calculator-form',
  templateUrl: './calculator-form.component.html',
  styleUrls: ['./calculator-form.component.css']
})

export class CalculatorFormComponent implements OnInit{

  answer:any;
  constructor(private http: HttpClient) { }

  onSubmit(data:string)
    {
      this.http.post('http://localhost:9080/calculate', data, {responseType:'text'}).subscribe((result)=>{
        this.answer = result;
        console.log(result)})
    }

  ngOnInit() {this.answer = ''}
    
}
