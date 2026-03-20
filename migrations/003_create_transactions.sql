CREATE TABLE transactions (
    id BIGSERIAL PRIMARY KEY,
    user_id BIGINT NOT NULL,
    asset_ticker VARCHAR(20) NOT NULL,
    type VARCHAR(10) NOT NULL, -- 'BUY' ou 'SELL'
    quantity DECIMAL(20,8) NOT NULL,
    price DECIMAL(15,2) NOT NULL,
    transaction_date DATE NOT NULL DEFAULT CURRENT_DATE, -- Data automática
    
    CONSTRAINT fk_user FOREIGN KEY(user_id) REFERENCES users(id) ON DELETE CASCADE,
    CONSTRAINT fk_asset FOREIGN KEY(asset_ticker) REFERENCES assets(ticker)
);
CREATE INDEX idx_transactions_user_id ON transactions(user_id);