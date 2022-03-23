import { Injectable } from '@angular/core';
import { HttpClient, HttpHeaders } from '@angular/common/http';

import { Observable } from 'rxjs';

import { Equation } from './equation';

@Injectable({
  providedIn: 'root'
})
export class EquationService {

  private storeUrl = 'calculator/store';
  private listUrl = 'calculator/list';
  private calculateUrl = 'calculator/calculate';

  constructor(private http: HttpClient) { }

  getEquations(): Observable<Equation[]> {
    return this.http.get<Equation[]>(this.listUrl);
  }

  storeEquation(equationString: string): Observable<Equation> {
    var toPost = { id: null, asString: equationString, value: null, variables: null };
    return this.http.post<Equation>(this.storeUrl, toPost);
  }

  calculateEquation(id: number, variables: Map<string, number>): Observable<Equation> {
    var toPost = { id: id, asString: null, value: null, variables: variables };
    return this.http.post<Equation>(this.calculateUrl, toPost);
  }
}
