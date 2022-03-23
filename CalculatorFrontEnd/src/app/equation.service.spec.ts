import { TestBed } from '@angular/core/testing';

import { EquationService } from './equation.service';

describe('EquationService', () => {
  let service: EquationService;

  beforeEach(() => {
    TestBed.configureTestingModule({});
    service = TestBed.inject(EquationService);
  });

  it('should be created', () => {
    expect(service).toBeTruthy();
  });
});
