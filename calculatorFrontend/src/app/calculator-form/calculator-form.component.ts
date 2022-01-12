import {Component} from '@angular/core'
import { HttpClient } from '@angular/common/http';

@Component({
  selector: 'calculator-form',
  templateUrl:'./calculator-form.component.html',
  styleUrls: ['./calculator-form.component.css']
})
export class CalculatorForm {

  constructor(private http: HttpClient) { }

  answer = "";
  onSubmit(event: any)
  {
    this.answer = "Calculating..."

    let data = event.target.equation.value

    this.http.post('http://localhost:9080/calculate', data, {responseType:'text'}).subscribe(
     (res)=> this.answer = res,
     (error)=> this.answer = "Sorry, too complex for me!",

    )

    event.target.equation.value = ""
  }
}
