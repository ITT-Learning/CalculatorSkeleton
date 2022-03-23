import { NgModule } from '@angular/core';
import { BrowserModule } from '@angular/platform-browser';
import { HttpClientModule } from '@angular/common/http';

import { AppRoutingModule } from './app-routing.module';
import { AppComponent } from './app.component';
import { SaveExpressionComponent } from './save-expression/save-expression.component';
import { ExpressionListComponent } from './expression-list/expression-list.component';
import { LastCalculationComponent } from './last-calculation/last-calculation.component';

@NgModule({
  declarations: [
    AppComponent,
    SaveExpressionComponent,
    ExpressionListComponent,
    LastCalculationComponent
  ],
  imports: [
    BrowserModule,
    AppRoutingModule,
    HttpClientModule
  ],
  providers: [],
  bootstrap: [AppComponent]
})
export class AppModule { }
