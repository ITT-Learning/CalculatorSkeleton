import { NgModule } from '@angular/core';
import { BrowserModule } from '@angular/platform-browser';

import { AppRoutingModule } from './app-routing.module';
import { AppComponent } from './app.component';
import { SaveExpressionComponent } from './save-expression/save-expression.component';
import { ExpressionListComponent } from './expression-list/expression-list.component';

@NgModule({
  declarations: [
    AppComponent,
    SaveExpressionComponent,
    ExpressionListComponent
  ],
  imports: [
    BrowserModule,
    AppRoutingModule
  ],
  providers: [],
  bootstrap: [AppComponent]
})
export class AppModule { }
