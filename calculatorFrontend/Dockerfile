FROM node:12-alpine
WORKDIR /angularProject
RUN npm install -g @angular/cli

COPY package*.json ./
RUN npm update
RUN npm install
